# O(n)
def solution(S):
    if not S:
        return 1

    stack = []
    temp = ['(', '{', '[']
    for i in S:
        if i in temp:
            stack.append(i)
        elif stack:
            if not(( i == ')' and stack.pop() == '(' ) or \
                ( i == '}' and stack.pop() == '{' ) or \
                ( i == ']' and stack.pop() == '[' )):
                return 0
        else:
            return 0
    if stack:
        return 0
    return 1