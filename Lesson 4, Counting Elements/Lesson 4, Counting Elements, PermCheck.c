/*
Author: Fernando Zuher
Place: Brazil
Date: 24 May 2020
About: codility.com -> Lesson 4, Counting Elements -> PermCheck

I solved this problem in the languages:
    C, C++, Java, Python and JavaScript. ;-)
*/

/*
A non-empty array A consisting of N integers is given.

A permutation is a sequence containing each element from 1 to N once, and only
once.

For example, array A such that:

    A[0] = 4
    A[1] = 1
    A[2] = 3
    A[3] = 2
is a permutation, but array A such that:

    A[0] = 4
    A[1] = 1
    A[2] = 3
is not a permutation, because value 2 is missing.

The goal is to check whether array A is a permutation.

Write a function:

int solution(int A[], int N);

that, given an array A, returns 1 if array A is a permutation and 0 if it is
not.

For example, given array A such that:

    A[0] = 4
    A[1] = 1
    A[2] = 3
    A[3] = 2
the function should return 1.

Given array A such that:

    A[0] = 4
    A[1] = 1
    A[2] = 3
the function should return 0.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..100,000];
each element of array A is an integer within the range [1..1,000,000,000].
*/


// Complexity: O(N log N) because of qsort(). 
// In Python the complexity is O(N) because array A was deduplicated
// (in that case sorting is unnecessary).
// Thus it was possible just compare its max element against N (from the
// original array) to check whether there is permutation.
// 13 lines
#include <stdlib.h> // qsort()
int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

int solution(int A[], int N)
{
	qsort(A, N, sizeof(int), compare);
	int i;
	for (i = 0; i < N && A[i] <= N && A[i] == i+1; i++);
	return i == N;
}