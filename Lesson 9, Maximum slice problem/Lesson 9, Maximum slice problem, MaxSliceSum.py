import math
def solution(A):
    max_ending = min(A)
    max_slice = -2_147_483_648
    for a in A:
        max_ending = max(max_ending, max_ending + a)
        max_slice = max(max_slice, max_ending)
    return max_slice


def solution(A):
    n, result = len(A), -2_147_483_648
    for p in range(n):
        sum = 0
        for q in range(p, n):
            sum += A[q]
            result = max(result, sum)
    return result