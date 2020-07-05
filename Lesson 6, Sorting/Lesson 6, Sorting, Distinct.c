/*
Author: Fernando Zuher
Place: Brazil
Date: 04 July 2020
About: codility.com -> Lesson 6, Sorting -> Distinct.c

I solved this problem in the languages:
    C, C++, Java, Python and JavaScript. ;-)
*/

/*
Write a function

int solution(int A[], int N);

that, given an array A consisting of N integers, returns the number of
distinct values in array A.

For example, given array A consisting of six elements such that:

 A[0] = 2    A[1] = 1    A[2] = 1
 A[3] = 2    A[4] = 3    A[5] = 1
the function should return 3, because there are 3 distinct values appearing
in array A, namely 1, 2 and 3.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [0..100,000];
each element of array A is an integer within the range [−1,000,000..1,000,000].

Copyright 2009–2020 by Codility Limited. All Rights Reserved. Unauthorized
copying, publication or disclosure prohibited.
*/
// 24 -> 16 lines. O(N*log(N)) or O(N).
#include <stdlib.h>

int compare(const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

int solution(int A[], int N)
{
	qsort(A, N, sizeof(int), compare);
	int count = 1;
	for (int i = 1; i < N; ++i)
		if (A[i] != A[i-1]) 
			count++;
	return N > 0 ? count : 0;
}
