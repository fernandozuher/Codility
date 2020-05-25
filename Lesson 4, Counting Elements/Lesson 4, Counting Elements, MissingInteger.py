# Author: Fernando Zuher
# Place: Brazil
# Date: 24 May 2020
# About: codility.com -> Lesson 4, Counting Elements -> MissingInteger
# 
# I solved this problem in the languages:
#     C, C++, Java, Python and JavaScript. ;-)
################################################################################
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
# 10 lines
def solution(A):

    N = len(A); temp = ['0'] * (N + 1);
    for i in range(N):
        if A[i] > 0 and A[i] <= N:
            temp[A[i]] = '1';

    try: index = 1 + temp[1:].index('0')
    except ValueError: return N + 1
    else: return index