#
# Author: Fernando Zuher
# Place: Brazil
# Date: 09 Sept 2020
# About: codility.com -> Lesson 4, Counting Elements -> MissingInteger
# 
# I solved this problem in the languages: C (11 lines), C++ (13 lines),
# Java (14 lines), Python (12 lines) and JavaScript (11 lines). ;-)
#
################################################################################
#
# Source: https://app.codility.com/programmers/lessons/4-counting_elements/missing_integer/
#
# This is a demo task.
# 
# Write a function:
# 
# def solution(A)
# 
# that, given an array A of N integers, returns the smallest positive integer
# (greater than 0) that does not occur in A.
# 
# For example, given A = [1, 3, 6, 4, 1, 2], the function should return 5.
# 
# Given A = [1, 2, 3], the function should return 4.
# 
# Given A = [−1, −3], the function should return 1.
# 
# Write an efficient algorithm for the following assumptions:
# 
# N is an integer within the range [1..100,000];
# each element of array A is an integer within the range [−1,000,000..1,000,000].
# 
# 12 lines, O(N) or O(N * log(N))
def solution(A):
    N = len(A)
    temp = [False] * (N + 1)

    for i in range(N):
        if A[i] > 0 and A[i] <= N:
            temp[A[i]] = True

    try:
        return 1 + temp[1:].index(False)
    except ValueError:
        return N + 1