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

class Solution { public int solution(int[] A); }

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

// 14 lines, O(N) or O(N * log(N))
class Solution {
    public int solution(int[] A) {
        final int N = A.length;
        boolean[] temp = new boolean[N + 1];

        for (int value : A)
            if (value > 0 && value <= N)
                temp[value] = true;
        
        // https://stackoverflow.com/questions/4962361/where-is-javas-array-indexof#19084357
        // "
        // If your array is not sorted and the type of the array is primitive,
        // you are out of luck with the Java API. Write your own for loop, or
        // your own static utility method, which will certainly have performance
        // advantages over the asList approach that involves some overhead of an
        // object instantiation. In case you're concerned that writing a brute
        // force for loop that iterates over all of the elements of the array is
        // not an elegant solution, accept that that is exactly what the Java API
        // is doing when you call indexOf.
        // "
        int i;
        for (i = 1; i < N + 1 && temp[i] == true; i++);
        return i;
    }
}
