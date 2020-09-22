/*
Author: Fernando Zuher
Place: Brazil
Date: 11 September 2020
About: codility.com -> Lesson 6, Sorting -> Distinct

I solved this problem in the languages: C (17 lines), C++ (5 lines),
Java (7 lines), Python (2 lines) and JavaScript (3 lines). ;-)
*/

/*
Source: https://app.codility.com/programmers/lessons/6-sorting/distinct/

Write a function

    int solution(vector<int> &A);

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

// 5 lines, O(N*log(N)) or O(N)
#include <unordered_set>
int solution(vector<int> &A)
{
    return ((std::unordered_set<int>) { A.begin(), A.end() }).size();
}
