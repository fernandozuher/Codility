#include <string.h> // strchr
int solution(char *S)
{
    int i = 0;
    for (char stack[100000], temp[] = {'(', '{', '['}; *S; S++)
        if (strchr(temp, *S))
            stack[i++] = *S;
        else if (!(i >= 1 && (*S == stack[--i]+1 || *S == stack[i]+2)))
            return 0;
    return !i;
}
// 11 lines. O(n)