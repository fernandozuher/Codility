int solution(int A[], int N)
{
    int result = -2147483648;
    for (int i = 0; i < N; i++)
        for (int j = i, sum = 0; j < N; sum += A[j++], result = sum > result ? sum : result);
    return result;
}