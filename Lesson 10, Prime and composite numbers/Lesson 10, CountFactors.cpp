#include <cmath>
int solution(int N)
{
    int factors {0}, limit {static_cast<int>(std::floor(sqrt(N)))};
    bool temp {std::pow(limit, 2) == N};
    limit -= temp;
    for (int i {1}; i <= limit; factors += !(N % i++) ? 2 : 0);
    return temp ? ++factors : factors;
}
// 9 lines, O(sqrt(N))
/*
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

int solution(int N);

that, given a positive integer N, returns the number of its factors.

For example, given N = 24, the function should return 8, because 24 has 8
factors, namely 1, 2, 3, 4, 6, 8, 12, 24. There are no other factors of 24.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..2,147,483,647].

Copyright 2009–2020 by Codility Limited. All Rights Reserved. Unauthorized
copying, publication or disclosure prohibited.
*/