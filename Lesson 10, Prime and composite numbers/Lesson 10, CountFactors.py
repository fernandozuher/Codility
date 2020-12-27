import math
def solution(N):
    factors, limit = 0, math.floor(math.sqrt(N))
    temp = math.pow(limit, 2) == N
    limit -= 1 if temp else 0
    for i in range(1, limit + 1):
        factors += 0 if (N % i) else 2
    return factors + 1 if temp else factors
# 8 lines, O(sqrt(N))
"""
Author: Fernando Zuher
Place: Sao Paulo, Brazil
Date: 26 December 2020
About: app.codility.com/programmers -> Lesson 10, Prime and composite numbers
        -> CountFactors

I solved this problem in the languages: C (10 lines), C++ (9 lines),
Java (10 lines), Python (8 lines) and JavaScript (7 lines). ;-)

Source:
https://app.codility.com/programmers/lessons/10-prime_and_composite_numbers/count_factors/

A positive integer D is a factor of a positive integer N if there exists an
integer M such that N = D * M.

For example, 6 is a factor of 24, because M = 4 satisfies the above condition
(24 = 6 * 4).

Write a function:

def solution(N)

that, given a positive integer N, returns the number of its factors.

For example, given N = 24, the function should return 8, because 24 has 8
factors, namely 1, 2, 3, 4, 6, 8, 12, 24. There are no other factors of 24.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..2,147,483,647].

Copyright 2009–2020 by Codility Limited. All Rights Reserved. Unauthorized
copying, publication or disclosure prohibited.
"""