def solution(H):
    blocks, stack = 0, []
    while len(H) > 0:
        stack.append(H[-1])
        for i in range(len(H)-2, -1, -1):
            
            if H[len(H)-1] < H[i]:
                blocks += 1
                del H[i]
    return blocks + len(stack)

"""
def solution(H):
    blocks, stack = 0, [H[0]]
    for i in range(1, len(H)):
        if H[i] < stack[-1]:
            stack.append(H[i])
            j = 0
            while j < len(stack)-1:
                if stack[j] > stack[-1]:
                    blocks += 1
                    del stack[j]
                elif stack[j] == stack[-1]:
                    del stack[j]
                else:
                    j += 1
        elif H[i] > stack[-1]:
            stack.append(H[i])
    return blocks + len(stack)
"""