/*
Author: Fernando Zuher
Place: Brazil
Date: 21 May 2020
About: codility.com -> Lesson 3, Time Complexity -> PermMissingElem

I solved this problem in the languages:
    C, C++, Java, Python and JavaScript. ;-)
*/

/*

An array A consisting of N different integers is given. The array contains
integers in the range [1..(N + 1)], which means that exactly one element is
missing.

Your goal is to find that missing element.

Write a function:

int solution(int A[], int N);

that, given an array A, returns the value of the missing element.

For example, given array A such that:

  A[0] = 2
  A[1] = 3
  A[2] = 1
  A[3] = 5
the function should return 4, as it is the missing element.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [0..100,000];
the elements of A are all distinct;
each element of array A is an integer within the range [1..(N + 1)].

*/

// 8 lines
int solution(int A[], int N)
{
	unsigned int sum_elements = 0;
    for (int i = 0; i < N; i++)
    	sum_elements += A[i];
    // (N*N + 3*N + 2) / 2 = 1 + 2 + ... + N + N+1
    return (((unsigned int)N*N + 3*N + 2) / 2) - sum_elements;
}