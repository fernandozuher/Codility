/*
Author: Fernando Zuher
Place: Brazil
Date: 20 July 2020
About: codility.com -> Lesson 2, Arrays -> OddOccurrencesInArray

I solved this problem in the languages: C (21 lines), C++ (16 lines),
Java (19 lines), Python (11 lines) and JavaScript (12 lines). ;-)

*/

/*
A non-empty array A consisting of N integers is given. The array contains an
odd number of elements, and each element of the array can be paired with
another element that has the same value, except for one element that is left
unpaired.

For example, in array A such that:

  A[0] = 9  A[1] = 3  A[2] = 9
  A[3] = 3  A[4] = 9  A[5] = 7
  A[6] = 9
the elements at indexes 0 and 2 have value 9,
the elements at indexes 1 and 3 have value 3,
the elements at indexes 4 and 6 have value 9,
the element at index 5 has value 7 and is unpaired.
Write a function:

int solution(vector<int> &A);

that, given an array A consisting of N integers fulfilling the above
conditions, returns the value of the unpaired element.

For example, given array A such that:

  A[0] = 9  A[1] = 3  A[2] = 9
  A[3] = 3  A[4] = 9  A[5] = 7
  A[6] = 9
the function should return 7, as explained in the example above.

Write an efficient algorithm for the following assumptions:

N is an odd integer within the range [1..1,000,000];
each element of array A is an integer within the range [1..1,000,000,000];
all but one of the values in A occur an even number of times.

Copyright 2009–2020 by Codility Limited. All Rights Reserved. Unauthorized
copying, publication or disclosure prohibited.

*/

// 16 lines. O(N) or O(N*log(N))
#include  <algorithm>
int solution(vector<int> &A)
{
    sort(A.begin(), A.end());
    auto temp {A[0]};
    auto flag {true};

    for (auto i {1ul}, N {A.size()}; i < N; i++)
        if (A[i] == temp)
            flag = !flag;
        else if (!flag)
            flag = {true}, temp = {A[i]};
        else
            break;
    return temp;
}

// In C++17
//for (auto [i, N, temp, flag] = tuple{1, A.size(), A[0], true}; i < N; i++)