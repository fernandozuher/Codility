def solution(A, B):
    i, alive, N, stack = 0, len(A), len(A), []
    while i < N:
        if B[i]:
            stack.append(i)
        elif stack:
            alive -= 1
            if A[stack[-1]] < A[i]:
                stack.pop(); i -= 1
        i += 1
    return alive