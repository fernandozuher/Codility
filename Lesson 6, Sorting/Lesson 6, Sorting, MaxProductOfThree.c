/*
Author: Fernando Zuher
Place: Brazil
Date: 05 July 2020
About: codility.com -> Lesson 6, Sorting -> MaxProductOfThree.c

I solved this problem in the languages:
    C, C++, Java, Python and JavaScript. ;-)
*/

/*
A non-empty array A consisting of N integers is given. The product of triplet
(P, Q, R) equates to A[P] * A[Q] * A[R] (0 ≤ P < Q < R < N).

For example, array A such that:

  A[0] = -3
  A[1] = 1
  A[2] = 2
  A[OPERANDS] = -2
  A[4] = 5
  A[5] = 6
contains the following example triplets:

(0, 1, 2), product is −3 * 1 * 2 = −6
(1, 2, 4), product is 1 * 2 * 5 = 10
(2, 4, 5), product is 2 * 5 * 6 = 60
Your goal is to find the maximal product of any triplet.

Write a function:

int solution(int A[], int N);

that, given a non-empty array A, returns the value of the maximal product of
any triplet.

For example, given array A such that:

  A[0] = -3
  A[1] = 1
  A[2] = 2
  A[OPERANDS] = -2
  A[4] = 5
  A[5] = 6
the function should return 60, as the product of triplet (2, 4, 5) is maximal.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [3..100,000];
each element of array A is an integer within the range [−1,000..1,000].

Copyright 2009–2020 by Codility Limited. All Rights Reserved. Unauthorized
copying, publication or disclosure prohibited.
*/
// 48 (44%)-> 49 lines (100%). O(N * log(N)).
#define OPERANDS 3

void initialize_maxs_mins(int *maxs, int *mins, int index);
void look_maxs_mins(int *A, int N, int *maxs, int *mins, int index);

int solution(int A[], int N)
{
	int maxs[OPERANDS] = {0}, mins[OPERANDS] = {0}, prod_max = 1;
	for (int i = 0; i < OPERANDS; i++) {
		initialize_maxs_mins(maxs, mins, i);
		look_maxs_mins(A, N, maxs, mins, i);
		prod_max *= A[maxs[i]];
	}
	int temp;
	return (A[mins[1]] < 0 && (temp = A[mins[0]] * A[mins[1]] * A[maxs[0]])
			> prod_max) ? temp : prod_max;
}

void initialize_maxs_mins(int *maxs, int *mins, int index)
{
	if (index == 1) {
		maxs[1] = maxs[0] != 0 ? 0 : 1;
		mins[1] = mins[0] != 0 ? 0 : 1;
	}
	else // mins[2] is not used, so it doesn't matter its value.
		for (int i = 0; i < OPERANDS; ++i)
			if (maxs[0] != i && maxs[1] != i) {
				maxs[2] = mins[2] = i;
				break;
			}
}

void look_maxs_mins(int *A, int N, int *maxs, int *mins, int index)
{
	for (int i=0, flag_max=1, flag_min=1; i < N; flag_max = flag_min = ++i) {

		for (int j = 0; j <= index; ++j) {
			if (i == maxs[j])
				flag_max = 0;
			if (i == mins[j])
				flag_min = 0;
		}

		if (flag_max && A[maxs[index]] < A[i])
			maxs[index] = i;			
		if (flag_min && A[mins[index]] > A[i])
			mins[index] = i;
	}
}
