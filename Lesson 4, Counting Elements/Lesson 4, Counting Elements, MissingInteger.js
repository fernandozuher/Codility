/*
Author: Fernando Zuher
Place: Brazil
Date: 09 Sept 2020
About: codility.com -> Lesson 4, Counting Elements -> MissingInteger

I solved this problem in the languages: C (11 lines), C++ (13 lines),
Java (14 lines), Python (12 lines) and JavaScript (11 lines). ;-)
*/

/*
Source: https://app.codility.com/programmers/lessons/4-counting_elements/missing_integer/

This is a demo task.

Write a function:

function solution(A);

that, given an array A of N integers, returns the smallest positive integer
(greater than 0) that does not occur in A.

For example, given A = [1, 3, 6, 4, 1, 2], the function should return 5.

Given A = [1, 2, 3], the function should return 4.

Given A = [−1, −3], the function should return 1.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..100,000];
each element of array A is an integer within the range [−1,000,000..1,000,000].

Copyright 2009–2020 by Codility Limited. All Rights Reserved. Unauthorized
copying, publication or disclosure prohibited.

*/

// 11 lines, O(N) or O(N * log(N))
function solution(A) {
    const N = A.length
    const temp = Array(N + 1).fill(false)

    for (const value of A)
        if (value > 0 && value <= N)
            temp[value] = true
    
    const i = temp.indexOf(false, 1)
    return i != -1 ? i : N+1
}
