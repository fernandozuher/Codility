#
# Author: Fernando Zuher
# Place: Brazil
# Date: 10 Sept 2020
# About: codility.com -> Lesson 5, Prefixing Sums -> CountDiv
# 
# I solved this problem in the languages: C (5 lines), C++ (5 lines),
# Java (7 lines), Python (3 lines) and JavaScript (4 lines). ;-)
#
##############################################################################
#
# Source: https://app.codility.com/programmers/lessons/5-prefix_sums/count_div/
#
# Write a function:
# 
# def solution(A, B, K)
# 
# that, given three integers A, B and K, returns the number of integers within
# the range [A..B] that are divisible by K, i.e.:
# 
# { i : A ≤ i ≤ B, i mod K = 0 }
# 
# For example, for A = 6, B = 11 and K = 2, your function should return 3,
# because there are three numbers divisible by 2 within the range [6..11],
# namely 6, 8 and 10.
# 
# Write an efficient algorithm for the following assumptions:
# 
# A and B are integers within the range [0..2,000,000,000];
# K is an integer within the range [1..2,000,000,000];
# A ≤ B.
#
# Copyright 2009–2020 by Codility Limited. All Rights Reserved. Unauthorized
# copying, publication or disclosure prohibited.
#
# 3 lines, O(1)
def solution(A, B, K):
    temp = int((B - A) / K)
    return temp+1 if (not(A % K) or not(B % K) or (A < K and (B%K + K-A) < K)) else temp