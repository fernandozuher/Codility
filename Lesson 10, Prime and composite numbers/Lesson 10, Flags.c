#include <math.h>

int solution(int A[], int N)
{
    int temp[N/2];

    int n = 0;
    for (int i = 1; i < N - 1; i++)
        if (A[i-1] < A[i] && A[i] > A[i+1])
            temp[n++] = i++;

    //printf("peaks: %d", n);

    //printf("\nabs: ");
    int result = 0;
    for (int i = 0, temp2; i < n-1; result += temp2 > n ? n : temp2, i++)
        temp2 = temp[i+1] - temp[i];

    //printf("\nresult: %d %d", result, n);

    if (n == 1)
        return 1;
    return ceil(sqrt(result));
}




// 60%
int solution(int A[], int N)
{
    int temp[N/2];
    //printf("array, N %d: ", N);
    //for (int i = 0; i < N; i++)
    //    printf("%d, ", A[i]);

    int n = 0;
    //printf("\npeaks: ");
    for (int i = 1; i < N - 1; i++)
        (A[i-1] < A[i] && A[i] > A[i+1] && (temp[n++] = i++));

    int flags = 0, max_flags = 0;
    //printf("\nflags, peaks %d: ", n);
    int n2 = n;
    while (n2) {
        for (int i = 0; i < n-1; i++) {
            for (int j = i+1; j < n; j++)
                if (temp[j] - temp[i] >= n2) {
                    flags++;
                    //printf("%d - %d >= %d (j = %d, ", temp[j], temp[i], n2, j);
                    i = j-1;
                    //printf("i = %d) ... ", i);
                    break;
                }
            if (flags == n2)
                break;
        }
        if (max_flags < flags)
            max_flags = flags;
        flags = 0;
        n2--;
    }

    //printf("\nmax_flags: %d", max_flags);
    return (max_flags || n == 1) ? ++max_flags : max_flags;
}