/*
Author: Fernando Zuher
Place: Brazil
Last edition: 20 July 2020
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
#include <bitset> // bitset
#include <string> // string
#include <algorithm> // max

int solution(int N)
{
    std::string const BINARY {std::bitset<sizeof(int) * 8>(N).to_string()};
    std::size_t i {}, j {}, max_gap {};
    while ((i = {BINARY.find('1', j)}) != std::string::npos &&
           (j = {BINARY.find('1', i+1)}) != std::string::npos)
               max_gap = {std::max(j - i - 1, max_gap)};
    return max_gap;
}

/* C++17
#include <bitset> // bitset
#include <tuple> // tupple
#include <algorithm> // find, max
using namespace std;

int solution(int N)
{
    for (
      auto [binary, i, j, max_gap] = tuple{bitset<sizeof(int)*8>(N).to_string(), 0, 0, 0} ;
      (i = {find(binary, j)} != string::npos && (j = {find(binary, i+1)} != string::npos ;
      max_gap = {max(j - i - 1, max_gap)}
    );
    return max_gap;
}
*/