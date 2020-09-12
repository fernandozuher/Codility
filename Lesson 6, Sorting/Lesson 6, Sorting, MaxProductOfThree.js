/*
Author: Fernando Zuher
Place: Brazil
Date: 11 September 2020
About: codility.com -> Lesson 6, Sorting -> MaxProductOfThree

I solved this problem in the languages: C (16 lines), C++ (13 lines),
Java (14 lines), Python (9 lines) and JavaScript (11 lines). ;-)
*/

/*
Source: https://app.codility.com/programmers/lessons/6-sorting/max_product_of_three/

A non-empty array A consisting of N integers is given. The product of triplet
(P, Q, R) equates to A[P] * A[Q] * A[R] (0 ≤ P < Q < R < N).

For example, array A such that:

  A[0] = -3
  A[1] = 1
  A[2] = 2
  A[3] = -2
  A[4] = 5
  A[5] = 6
contains the following example triplets:

(0, 1, 2), product is −3 * 1 * 2 = −6
(1, 2, 4), product is 1 * 2 * 5 = 10
(2, 4, 5), product is 2 * 5 * 6 = 60
Your goal is to find the maximal product of any triplet.

Write a function:

    function solution(A);

that, given a non-empty array A, returns the value of the maximal product of
any triplet.

For example, given array A such that:

  A[0] = -3
  A[1] = 1
  A[2] = 2
  A[3] = -2
  A[4] = 5
  A[5] = 6
the function should return 60, as the product of triplet (2, 4, 5) is maximal.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [3..100,000];
each element of array A is an integer within the range [−1,000..1,000].

Copyright 2009–2020 by Codility Limited. All Rights Reserved. Unauthorized
copying, publication or disclosure prohibited.

*/

// 11 lines, O(N * log(N))
function solution(A) {  
    A.sort(function(a, b){return a - b})

    const N = A.length
    const max_prod = A[N-1] * A[N-2] * A[N-3];
    let temp = max_prod;

    if (A[1] < 0)
        temp = A[0]*A[1] * A[N-1];
    return temp >= max_prod ? temp : max_prod;
}