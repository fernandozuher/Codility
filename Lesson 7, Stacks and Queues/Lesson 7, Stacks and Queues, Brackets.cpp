// O(n)
#include <string>
int solution(string &S)
{
    if (S.empty())
        return 1;

    std::vector<char> stack;
    std::array<char> {'(', '{', '['};
    
    while (S) {
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