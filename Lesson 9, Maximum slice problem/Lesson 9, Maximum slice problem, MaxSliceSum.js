function solution(A) {
    let result = -2147483648, N = A.length
    for (let i in A)
        for (let j = i, sum = 0; j < N; sum += A[j++], result = Math.max(sum, result));
    return result;
}