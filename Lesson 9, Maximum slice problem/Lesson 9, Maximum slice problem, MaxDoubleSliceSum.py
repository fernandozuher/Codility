def solution(A):
    max_sum = current_sum = A[0]
    x = temp_x = 0
    i = 1

    for value in A[1:]:

        temp = current_sum + value

        if temp > value:
            current_sum = temp
        else:
            current_sum = value
            temp_x = i

        if current_sum > max_sum:
            max_sum = current_sum
            x = temp_x
            z = i

        i += 1

    if x - 1 == -1:
        max_sum -= A[0]
    else:
        x -= 1

    if z == len(A)-1:
        max_sum -= A[-1]

        if max_sum - A[z-1] > max_sum:
            max_sum -= A[z-1]
            z -= 1
    else:
        z += 1


    """
    y = 0
    if x + 2 == z and z + 1 < len(A):
        pass
    else:
        y = min(A[x+1:z+1])
        max_sum -= y

    print(x, z, len(A[x+1:z+1]), y)
    """
    if x + 2 != z:
        y = min(A[x+1:z])
        max_sum -= y
    return max_sum