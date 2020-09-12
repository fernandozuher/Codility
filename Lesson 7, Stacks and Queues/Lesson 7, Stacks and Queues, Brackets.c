// O(n)
int solution(char *S)
{
    if (!S[0])
        return 1;

    char stack[100000];
    int i = -1;
    char temp[] = {'(', '{', '['};
    
    while (*S) {
        if (strchr(temp, *S))
            stack[++i] = *S;
        else if (i >= 0) {
            if (!(( *S == ')' && stack[i--] == '(' ) || \
                ( *S == '}' && stack[i--] == '{' ) || \
                ( *S == ']' && stack[i--] == '[' )))
                return 0;
        }
        else
            return 0;
        S++;
    }
    if (i >= 0)
        return 0;
    return 1;
}