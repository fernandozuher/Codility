int solution(int A[], int B[], int N)
{
    int alive = N;
    for (int i = 0, j = 0, stack[100000]; i < N; i++)
        if (B[i])
            stack[j++] = i;
        else if (j) {
            alive--;
            if (A[stack[j-1]] < A[i])
                j--, i--;
        }
    return alive;
}
// O(N)