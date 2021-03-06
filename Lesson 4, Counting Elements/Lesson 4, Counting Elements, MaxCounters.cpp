/*
Author: Fernando Zuher
Place: Brazil
Date: 22 August 2020
About: codility.com -> Lesson 4, Counting Elements -> MaxCounters

I solved this problem in the languages: C (25 lines), C++ (26 lines),
Java (33 lines), Python (24 lines) and JavaScript (27 lines). ;-)
*/

/*
You are given N counters, initially set to 0, and you have two possible
operations on them:

increase(X) − counter X is increased by 1,
max counter − all counters are set to the maximum value of any counter.
A non-empty array A of M integers is given. This array represents consecutive
operations:

if A[K] = X, such that 1 ≤ X ≤ N, then operation K is increase(X),
if A[K] = N + 1 then operation K is max counter.
For example, given integer N = 5 and array A such that:

    A[0] = 3
    A[1] = 4
    A[2] = 4
    A[3] = 6
    A[4] = 1
    A[5] = 4
    A[6] = 4
the values of the counters after each consecutive operation will be:

    (0, 0, 1, 0, 0)
    (0, 0, 1, 1, 0)
    (0, 0, 1, 2, 0)
    (2, 2, 2, 2, 2)
    (3, 2, 2, 2, 2)
    (3, 2, 2, 3, 2)
    (3, 2, 2, 4, 2)
The goal is to calculate the value of every counter after all operations.

Write a function:

    vector<int> solution(int N, vector<int> &A);

that, given an integer N and a non-empty array A consisting of M integers,
returns a sequence of integers representing the values of the counters.

Result array should be returned as a vector of integers.

For example, given:

    A[0] = 3
    A[1] = 4
    A[2] = 4
    A[3] = 6
    A[4] = 1
    A[5] = 4
    A[6] = 4
the function should return [3, 2, 2, 4, 2], as explained above.

Write an efficient algorithm for the following assumptions:

N and M are integers within the range [1..100,000];
each element of array A is an integer within the range [1..N + 1].

Copyright 2009–2020 by Codility Limited. All Rights Reserved. Unauthorized
copying, publication or disclosure prohibited.

*/

#include <vector> // vector<T>
#include <algorithm> // fill()

// 26 lines, O(N + M)
#include <cstring> // memset()
vector<int> solution(int N, vector<int> &A)
{
    int current_max {}, max {}, size {N + 1};
    std::vector<int> counter(size);
    bool flag_max {false};

    for (auto value : A)

        if (value < size) {
            if (flag_max) { // memset is faster than std::fill() during the evaluation of this exercise
                memset(&counter[0], 0, sizeof(counter[0]) * counter.size());
                flag_max = false;
            }
            if (++counter[value] > current_max)
                current_max++;
        }
        else if (!flag_max)
            max += current_max, flag_max = true, current_max = 0;

    if (flag_max)
        std::fill(counter.begin(), counter.end(), max);
    else if (max)
        for(auto& value : counter) value += max;
    return {counter.begin() + 1, counter.end()};
}
