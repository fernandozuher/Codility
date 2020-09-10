/*
Author: Fernando Zuher
Place: Brazil
Date: 10 September 2020
About: codility.com -> Lesson 5, Prefixing Sums -> PassingCars

I solved this problem in the languages: C (12 lines), C++ (12 lines),
Java (13 lines), Python (10 lines) and JavaScript (11 lines). ;-)
*/

/*
Source: https://app.codility.com/programmers/lessons/5-prefix_sums/passing_cars/

A non-empty array A consisting of N integers is given. The consecutive
elements of array A represent consecutive cars on a road.

Array A contains only 0s and/or 1s:

0 represents a car traveling east,
1 represents a car traveling west.
The goal is to count passing cars. We say that a pair of cars (P, Q), where
0 ≤ P < Q < N, is passing when P is traveling to the east and Q is traveling
to the west.

For example, consider array A such that:

  A[0] = 0
  A[1] = 1
  A[2] = 0
  A[3] = 1
  A[4] = 1
We have five pairs of passing cars: (0, 1), (0, 3), (0, 4), (2, 3), (2, 4).

Write a function:

class Solution { public int solution(int[] A); }

that, given a non-empty array A of N integers, returns the number of pairs of
passing cars.

The function should return −1 if the number of pairs of passing cars exceeds
1,000,000,000.

For example, given:

  A[0] = 0
  A[1] = 1
  A[2] = 0
  A[3] = 1
  A[4] = 1
the function should return 5, as explained above.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..100,000];
each element of array A is an integer that can have one of the following
values: 0, 1.

Copyright 2009–2020 by Codility Limited. All Rights Reserved. Unauthorized
copying, publication or disclosure prohibited.

*/

// 13 lines, O(N)
class Solution {
    public int solution(int[] A) {
        int total = 0, zeros = 0;
        for (int value : A)
            if (value == 1) {
                if ((total += zeros) > 1.0e9) 
                    return -1;
            }
            else
                zeros++;
        return total;
    }
}