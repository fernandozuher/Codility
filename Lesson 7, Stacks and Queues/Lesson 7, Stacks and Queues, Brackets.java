// O(n)
    CONTINUAR
#include <string>
class Solution {
    public int solution(String S) {
        if (S.isEmpty())
            return 1;

        char[] stack;
        String temp = "({[";
        int i = -1;
        
        while (!S.isEmpty()) {
            
            if (temp.indexOf(S.substring(0, 1)) != -1)
                stack[++i] = S.substring(0, 1);
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
}