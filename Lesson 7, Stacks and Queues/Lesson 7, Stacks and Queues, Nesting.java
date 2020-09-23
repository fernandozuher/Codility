class Solution {
    public int solution(String S) {
        int i = 0, j = 0, N = S.length();
        for (; i >= 0 && j < N; i += S.charAt(j++) == '(' ? 1 : -1);
        return i == 0 ? 1 : 0;
    }
}
// 7 lines, O(n)
/*
Author: Fernando Zuher
Place: Sao Paulo, Brazil
Date: 23 September 2020
About: codility.com -> Lesson 7, Stacks and Queues -> Nesting

I solved this problem in the languages: C (6 lines), C++ (6 lines),
Java (7 lines), Python (6 lines) and JavaScript (5 lines). ;-)

Source: https://app.codility.com/programmers/lessons/7-stacks_and_queues/nesting/

A string S consisting of N characters is called properly nested if:

S is empty;
S has the form "(U)" where U is a properly nested string;
S has the form "VW" where V and W are properly nested strings.
For example, string "(()(())())" is properly nested but string "())" isn't.

Write a function:

int solution(char *S);

that, given a string S consisting of N characters, returns 1 if string S is
properly nested and 0 otherwise.

For example, given S = "(()(())())", the function should return 1 and given
S = "())", the function should return 0, as explained above.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [0..1,000,000];
string S consists only of the characters "(" and/or ")".

Copyright 2009–2020 by Codility Limited. All Rights Reserved. Unauthorized
copying, publication or disclosure prohibited.
*/