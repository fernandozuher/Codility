/*
Author: Fernando Zuher
Place: Brazil
Date: 20 July 2020
About: codility.com -> Lesson 3, Time Complexity -> PermMissingElem

I solved this problem in the languages: C (6 lines), C++ (6 lines),
Java (7 lines), Python (3 lines) and JavaScript (4 lines). ;-)
*/

/*
Source:
https://app.codility.com/programmers/lessons/3-time_complexity/perm_missing_elem/

An array A consisting of N different integers is given. The array contains
integers in the range [1..(N + 1)], which means that exactly one element is
missing.

Your goal is to find that missing element.

Write a function:

int solution(vector<int> &A);

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

Copyright 2009–2020 by Codility Limited. All Rights Reserved.
Unauthorized copying, publication or disclosure prohibited.

*/

// 6 lines. O(N) or O(N * log(N))
#include <numeric>
int solution(vector<int> &A)
{   // (N*N + 3*N + 2) / 2 = 1 + 2 + ... + N + N+1
    auto N {A.size()}, expected_sum {(N*N + 3*N + 2) / 2};
    return expected_sum - std::accumulate(A.begin(), A.end(), 0);
}