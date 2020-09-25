#include <stdlib.h>     /* qsort */

int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

int solution(int H[], int N)
{
    if (N == 1)
        return 1;
        
    int blocks = 0, j = 0, stack[100000];
    stack[0] = H[0];
    for (int i = 1; i < N; i++) {
        if (H[i] < stack[j]) {
            blocks++;
            stack[j] = H[i];
            if (j - 1 >= 0 && stack[j-1] == stack[j])
                j--;
            for (int i = 0; i < j; i++) {
                if (stack[i] != 0 && stack[i] > stack[j]) {
                    blocks++;
                    stack[i] = 0;
                }
            }
        }
        else if (H[i] > stack[j])
            stack[++j] = H[i];
    }
    /*qsort (stack, j+1, sizeof(int), compare);
    int k = 0;
    for (int i = 0; i < j; i++)
        if (stack[i] != stack[i+1])
            k++;
    */
    return blocks + 1;
}