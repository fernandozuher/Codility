/*
Author: Fernando Zuher
Place: Brazil
Date: 20 July 2020
About: codility.com -> Lesson 3, Time Complexity -> TapeEquilibrium

I solved this problem in the languages: C (14 lines), C++ (15 lines),
Java (15 lines), Python (9 lines) and JavaScript (11 lines). ;-)

*/

/*
Source:
https://app.codility.com/programmers/lessons/3-time_complexity/tape_equilibrium/

A non-empty array A consisting of N integers is given. Array A represents
numbers on a tape.

Any integer P, such that 0 < P < N, splits this tape into two non-empty parts:
A[0], A[1], ..., A[P − 1] and A[P], A[P + 1], ..., A[N − 1].

The difference between the two parts is the value of:
|(A[0] + A[1] + ... + A[P − 1]) − (A[P] + A[P + 1] + ... + A[N − 1])|

In other words, it is the absolute difference between the sum of the first part
and the sum of the second part.

For example, consider array A such that:

  A[0] = 3
  A[1] = 1
  A[2] = 2
  A[3] = 4
  A[4] = 3
We can split this tape in four places:

P = 1, difference = |3 − 10| = 7
P = 2, difference = |4 − 9| = 5
P = 3, difference = |6 − 7| = 1
P = 4, difference = |10 − 3| = 7
Write a function:

int solution(int A[], int N);

that, given a non-empty array A of N integers, returns the minimal difference
that can be achieved.

For example, given:

  A[0] = 3
  A[1] = 1
  A[2] = 2
  A[3] = 4
  A[4] = 3
the function should return 1, as explained above.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [2..100,000];
each element of array A is an integer within the range [−1,000..1,000].

Copyright 2009–2020 by Codility Limited. All Rights Reserved. Unauthorized
copying, publication or disclosure prohibited.

*/

// 14 lines. O(N)
#include <stdlib.h> // abs()
int solution(int A[], int N)
{
    int remaining = 0;
    for (int i = 1; i < N; remaining += A[i++]);

    unsigned min = abs(A[0] - remaining);
    for (int i = 1, first_part = A[0], temp; i < N; i++) {
        if (min > (temp = abs(first_part - remaining)))
            min = temp;
        first_part += A[i], remaining -= A[i];
    }
    return min;
}