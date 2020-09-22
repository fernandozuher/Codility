def solution(S):
    stack, str = [], "{[("
    for ch in S:
        if ch in str:
            stack.append(ch)
        elif stack and (ord(ch) == ord(stack[-1])+1 or ord(ch) == ord(stack[-1])+2):
            stack.pop()
        else:
            return 0
    return 0 if stack else 1
# 10 lines, O(n)
"""
Author: Fernando Zuher
Place: Sao Paulo, Brazil
Date: 22 September 2020
About: codility.com -> Lesson 6, Sorting -> Brackets

I solved this problem in the languages: C (11 lines), C++ (15 lines),
Java (16 lines), Python (10 lines) and JavaScript (12 lines). ;-)

Source: https://app.codility.com/programmers/lessons/7-stacks_and_queues/brackets/

A string S consisting of N characters is considered to be properly nested if
any of the following conditions is true:

S is empty;
S has the form "(U)" or "[U]" or "{U}" where U is a properly nested string;
S has the form "VW" where V and W are properly nested strings.
For example, the string "{[()()]}" is properly nested but "([)()]" is not.

Write a function:

def solution(S)

that, given a string S consisting of N characters, returns 1 if S is properly
nested and 0 otherwise.

For example, given S = "{[()()]}", the function should return 1 and given
S = "([)()]", the function should return 0, as explained above.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [0..200,000];
string S consists only of the following characters: "(", "{", "[", "]", "}"
and/or ")".

Copyright 2009–2020 by Codility Limited. All Rights Reserved. Unauthorized
copying, publication or disclosure prohibited.
"""