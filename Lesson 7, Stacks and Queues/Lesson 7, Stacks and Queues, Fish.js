function solution(A, B) {
    let i = 0, alive = A.length, N = A.length, stack = [] 
    for (; i < N; i++) {
        if (parseInt(B[i]) === 1)
            stack.push(i)
        else if (stack.length > 0) {
            alive--
            if (parseInt(A[stack.length - 1]) < parseInt(A[i])) {
                stack.pop()
                i--
            }
        }
    }
    return alive
}