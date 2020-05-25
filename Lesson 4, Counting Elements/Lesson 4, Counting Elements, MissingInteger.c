/*
Author: Fernando Zuher
Place: Brazil
Date: 23 May 2020
About: codility.com -> Lesson 4, Counting Elements -> MissingInteger

I solved this problem in the languages:
    C, C++, Java, Python and JavaScript. ;-)
*/

/*
This is a demo task.

Write a function:

int solution(int A[], int N);

that, given an array A of N integers, returns the smallest positive integer
(greater than 0) that does not occur in A.

For example, given A = [1, 3, 6, 4, 1, 2], the function should return 5.

Given A = [1, 2, 3], the function should return 4.

Given A = [−1, −3], the function should return 1.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..100,000];
each element of array A is an integer within the range [−1,000,000..1,000,000].
*/

// 13 lines
int solution(int A[], int N){

    char temp[N + 1];
    for (int i = 1; i < N + 1; temp[i++] = '0');

    for (int i = 0; i < N; i++)
        if (A[i] > 0 && A[i] <= N)
            temp[A[i]] = '1';

    int i;
    for (i = 1; i < N + 1 && temp[i] == '1'; i++);
    return i;
}