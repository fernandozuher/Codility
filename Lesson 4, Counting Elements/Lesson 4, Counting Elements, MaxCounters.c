/*
Author: Fernando Zuher
Place: Brazil
Date: 22 August 2020
About: codility.com -> Lesson 4, Counting Elements -> MaxCounters

I solved this problem in the languages: C (25 lines), C++ (26 lines),
Java (33 lines), Python (24 lines) and JavaScript (27 lines). ;-)
*/

/*
You are given N counters, initially set to 0, and you have two possible
operations on them:

increase(X) − counter X is increased by 1,
max counter − all counters are set to the maximum value of any counter.
A non-empty array A of M integers is given. This array represents consecutive
operations:

if A[K] = X, such that 1 ≤ X ≤ N, then operation K is increase(X),
if A[K] = N + 1 then operation K is max counter.
For example, given integer N = 5 and array A such that:

    A[0] = 3
    A[1] = 4
    A[2] = 4
    A[3] = 6
    A[4] = 1
    A[5] = 4
    A[6] = 4
the values of the counters after each consecutive operation will be:

    (0, 0, 1, 0, 0)
    (0, 0, 1, 1, 0)
    (0, 0, 1, 2, 0)
    (2, 2, 2, 2, 2)
    (3, 2, 2, 2, 2)
    (3, 2, 2, 3, 2)
    (3, 2, 2, 4, 2)
The goal is to calculate the value of every counter after all operations.

Assume that the following declarations are given:

struct Results {
  int * C;
  int L; // Length of the array
};

Write a function:

struct Results solution(int N, int A[], int M);

that, given an integer N and a non-empty array A consisting of M integers,
returns a sequence of integers representing the values of the counters.

Result array should be returned as a structure Results.

For example, given:

    A[0] = 3
    A[1] = 4
    A[2] = 4
    A[3] = 6
    A[4] = 1
    A[5] = 4
    A[6] = 4
the function should return [3, 2, 2, 4, 2], as explained above.

Write an efficient algorithm for the following assumptions:

N and M are integers within the range [1..100,000];
each element of array A is an integer within the range [1..N + 1].

Copyright 2009–2020 by Codility Limited. All Rights Reserved. Unauthorized
copying, publication or disclosure prohibited.
*/

// 25 lines, O(N + M)
#include <string.h>
struct Results solution(int N, int A[], int M)
{
    int max = 0, flag_max = 0, size = N + 1;
    int *counter = (int*) calloc(size, sizeof(int));

    for (int i = 0, current_max = 0; i < M; i++)

        if (A[i] < size) {
            if (flag_max) {
                memset(counter, 0, (N + 1) * sizeof(int)); // because N + 1
                flag_max = 0;
            }
            if (++counter[A[i]] > current_max)
                current_max++;
        }
        else if (!flag_max)
            max += current_max, flag_max = 1, current_max = 0;

    if (flag_max)
        for (int i = 1; i < size; counter[i++] = max);
    else if (max)
        for (int i = 1; i < size; counter[i++] += max);
    return (struct Results) {++counter, N};
}