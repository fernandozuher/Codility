#include <string.h> // memcpy()
int compare (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

int solution(int A[], int N)
{
    int sorted_A[N];
    memcpy(sorted_A, A, N * sizeof(int));
    qsort(sorted_A, N, sizeof(int), compare);

    int max = 0, dominator = sorted_A[0], previous = 0, count = 0;

    for (int i = 0; i < N; i++)
        if (sorted_A[previous] == sorted_A[i])
            count++;
        else {
            if (count > max)
                max = count, dominator = sorted_A[previous];
            count = 1, previous = i;
        }
    if (count > max)
        max = count, dominator = sorted_A[previous];

    if (max > N / 2)
        for (int i = 0; i < N; i++)
            if (A[i] == dominator)
                return i;
    return -1;
}
// 31 lines, O(N*log(N)) or O(N)
/*
Author: Fernando Zuher
Place: Sao Paulo, Brazil
Date: 12 October 2020
About: app.codility.com/programmers -> Lesson 8, Leader -> Dominator

I solved this problem in the languages: C (31 lines), C++ (11 lines),
Java (19 lines), Python (5 lines) and JavaScript (7 lines). ;-)

Source: https://app.codility.com/programmers/lessons/8-leader/dominator/

An array A consisting of N integers is given. The dominator of array A is the
value that occurs in more than half of the elements of A.

For example, consider array A such that

 A[0] = 3    A[1] = 4    A[2] =  3
 A[3] = 2    A[4] = 3    A[5] = -1
 A[6] = 3    A[7] = 3
The dominator of A is 3 because it occurs in 5 out of 8 elements of A (namely
in those with indices 0, 2, 4, 6 and 7) and 5 is more than a half of 8.

Write a function

int solution(int A[], int N);

that, given an array A consisting of N integers, returns index of any element
of array A in which the dominator of A occurs. The function should return −1
if array A does not have a dominator.

For example, given array A such that

 A[0] = 3    A[1] = 4    A[2] =  3
 A[3] = 2    A[4] = 3    A[5] = -1
 A[6] = 3    A[7] = 3
the function may return 0, 2, 4, 6 or 7, as explained above.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [0..100,000];
each element of array A is an integer within the range
[−2,147,483,648..2,147,483,647].

Copyright 2009–2020 by Codility Limited. All Rights Reserved. Unauthorized
copying, publication or disclosure prohibited.
*/