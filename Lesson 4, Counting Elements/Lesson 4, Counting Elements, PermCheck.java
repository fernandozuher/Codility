/*
Author: Fernando Zuher
Place: São Paulo, Brazil
Date: 11 August 2020
About: codility.com -> Lesson 4, Counting Elements -> PermCheck

I solved this problem in the languages: C (13 lines), C++ (7 lines),
Java (14 lines), Python (2 lines) and JavaScript (3 lines). ;-)

*/

/*
Source: https://app.codility.com/programmers/lessons/4-counting_elements/perm_check/

A non-empty array A consisting of N integers is given.

A permutation is a sequence containing each element from 1 to N once, and only
once.

For example, array A such that:

    A[0] = 4
    A[1] = 1
    A[2] = 3
    A[3] = 2
is a permutation, but array A such that:

    A[0] = 4
    A[1] = 1
    A[2] = 3
is not a permutation, because value 2 is missing.

The goal is to check whether array A is a permutation.

Write a function:

class Solution { public int solution(int[] A); }

that, given an array A, returns 1 if array A is a permutation and 0 if it is
not.

For example, given array A such that:

    A[0] = 4
    A[1] = 1
    A[2] = 3
    A[3] = 2
the function should return 1.

Given array A such that:

    A[0] = 4
    A[1] = 1
    A[2] = 3
the function should return 0.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..100,000];
each element of array A is an integer within the range [1..1,000,000,000].

Copyright 2009–2020 by Codility Limited. All Rights Reserved. Unauthorized
copying, publication or disclosure prohibited.

*/

// 14 lines. O(N) or O(N * log(N))
import java.util.List;
import java.util.Arrays;
import java.util.stream.Collectors;
import java.util.Set;
import java.util.HashSet;
import java.util.Collections;

class Solution {
    public int solution(int[] A) {
        List<Integer> list = Arrays.stream(A).boxed().collect(Collectors.toList());
        Set<Integer> set = new HashSet<Integer>(list);
        return Collections.max(list) == A.length && set.size() == A.length ? 1 : 0;
    }
}