/*
Author: Fernando Zuher
Place: Brazil
Date: 10 July 2020
About: codility.com -> Lesson 1, Iterations -> BinaryGap

I solved this problem in the languages: C (13 lines), C++ (13 lines),
Java (9 lines), Python (9 lines) and JavaScript (8 lines). ;-)

*/

/*
A binary gap within a positive integer N is any maximal sequence of consecutive
zeros that is surrounded by ones at both ends in the binary representation of N.

For example, number 9 has binary representation 1001 and contains a binary gap
of length 2. The number 529 has binary representation 1000010001 and contains
two binary gaps: one of length 4 and one of length 3. The number 20 has binary
representation 10100 and contains one binary gap of length 1. The number 15 has
binary representation 1111 and has no binary gaps. The number 32 has binary
representation 100000 and has no binary gaps.

Write a function:

int solution(int N);

that, given a positive integer N, returns the length of its longest binary gap.
The function should return 0 if N doesn't contain a binary gap.

For example, given N = 1041 the function should return 5, because N has binary
representation 10000010001 and so its longest binary gap is of length 5.
Given N = 32 the function should return 0, because N has binary representation
'100000' and thus no binary gaps.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..2,147,483,647].

Copyright 2009–2020 by Codility Limited. All Rights Reserved. Unauthorized
copying, publication or disclosure prohibited.

*/
// 13 lines
int solution(int N)
{
    int max_gap = 0;
    for (int x = 0, i = -1, j = 0, temp_max = 0; N >= 2; N /= 2) {
        for (; N >= 2 && !(N % 2); N /= 2, x++); // decimal -> bit
        j = i == -1 ? i = x++ : x++;
                
        if (j != i && (temp_max = j - i - 1) > max_gap)
            max_gap = temp_max;
        i = j;
    }
    return max_gap;
}