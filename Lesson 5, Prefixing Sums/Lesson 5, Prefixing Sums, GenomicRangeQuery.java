/*
Author: Fernando Zuher
Place: Brazil
Date: 13 September 2020
About: codility.com -> Lesson 5, Prefixing Sums -> GenomicRangeQuery

I solved this problem in the languages: C (47 lines), C++ (40 lines),
Java (48 lines), Python (22 lines) and JavaScript (33 lines). ;-)
*/

/*
Source: https://app.codility.com/programmers/lessons/5-prefix_sums/genomic_range_query/

A DNA sequence can be represented as a string consisting of the letters A, C,
G and T, which correspond to the types of successive nucleotides in the
sequence. Each nucleotide has an impact factor, which is an integer.
Nucleotides of types A, C, G and T have impact factors of 1, 2, 3 and 4,
respectively. You are going to answer several queries of the form: What is
the minimal impact factor of nucleotides contained in a particular part of
the given DNA sequence?

The DNA sequence is given as a non-empty string S = S[0]S[1]...S[N-1]
consisting of N characters. There are M queries, which are given in non-empty
arrays P and Q, each consisting of M integers. The K-th query (0 ≤ K < M)
requires you to find the minimal impact factor of nucleotides contained in
the DNA sequence between positions P[K] and Q[K] (inclusive).

For example, consider string S = CAGCCTA and arrays P, Q such that:

    P[0] = 2    Q[0] = 4
    P[1] = 5    Q[1] = 5
    P[2] = 0    Q[2] = 6
The answers to these M = 3 queries are as follows:

The part of the DNA between positions 2 and 4 contains nucleotides G and C
(twice), whose impact factors are 3 and 2 respectively, so the answer is 2.
The part between positions 5 and 5 contains a single nucleotide T, whose
impact factor is 4, so the answer is 4.
The part between positions 0 and 6 (the whole string) contains all
nucleotides, in particular nucleotide A whose impact factor is 1, so the
answer is 1.

Write a function:

    class Solution { public int[] solution(String S, int[] P, int[] Q); }

that, given a non-empty string S consisting of N characters and two non-empty
arrays P and Q consisting of M integers, returns an array consisting of M
integers specifying the consecutive answers to all queries.

Result array should be returned as a structure Results.

For example, given the string S = CAGCCTA and arrays P, Q such that:

    P[0] = 2    Q[0] = 4
    P[1] = 5    Q[1] = 5
    P[2] = 0    Q[2] = 6
the function should return the values [2, 4, 1], as explained above.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..100,000];
M is an integer within the range [1..50,000];
each element of arrays P, Q is an integer within the range [0..N − 1];
P[K] ≤ Q[K], where 0 ≤ K < M;
string S consists only of upper-case English letters A, C, G, T.

Copyright 2009–2020 by Codility Limited. All Rights Reserved. Unauthorized
copying, publication or disclosure prohibited.

*/

// 48 lines, O(N + M), 87 to 100% =/
import java.util.Arrays;

class Solution {

    private int convert(final char nucl) {
        switch(nucl) {
            case 'A':
                return 0;
            case 'C':
                return 1;
            case 'G':
                return 2;
            default:
                return 3;
        }
    }

    public int[] solution(String S, int[] P, int[] Q) {

        int min = Arrays.stream(P).min().getAsInt();
        int max = Arrays.stream(Q).max().getAsInt();
        
        final int nucleotides = 4;
        int[][] matrix = new int[nucleotides][max+1];
        int[] nucleotides_size = new int[nucleotides]; // Default with 0, default

        // Convert only the range of array S that will be looked from min to max (inclusive).
        for (int i = min, j; i < max+1; i++) {
            j = convert(S.charAt(i));
            matrix[j][nucleotides_size[j]++] = i;
        }
        
        final int M = P.length;
        int[] A = new int[M];

        for (int i = 0; i < M; i++)
            for (int j = 0; j < nucleotides; j++)
                for (int k = 0; k < nucleotides_size[j]; k++)
                    if (matrix[j][k] >= P[i]) {
                        if (matrix[j][k] <= Q[i]) {
                            A[i] = j + 1;
                            j = nucleotides;
                        }
                        break;
                    }
        return A;
    }
}


// 48 lines, O(N + M), 87 to 100% =/
import java.util.Arrays;

class Solution {

    private int convert(final char nucl) {
        switch(nucl) {
            case 'A':
                return 0;
            case 'C':
                return 1;
            case 'G':
                return 2;
            default:
                return 3;
        }
    }

    public int[] solution(String S, int[] P, int[] Q) {

        int min = Arrays.stream(P).min().getAsInt();
        int max = Arrays.stream(Q).max().getAsInt();
        
        final int nucleotides = 4;
        int[][] matrix = new int[nucleotides][max+2];
        int[] nucleotides_size = new int[nucleotides]; // Default with 0, default
        boolean[] flag = new boolean[4];

        // Convert only the range of array S that will be looked from min to max (inclusive).
        for (int i = min, j; i < max + 1; i++) {
            j = convert(S.charAt(i));
            if (nucleotides_size[j]-1>=0 && matrix[j][nucleotides_size[j]-1] + 1 == i) {
                if (!flag[j]) {
                    if (nucleotides_size[j]-2>=0 && matrix[j][nucleotides_size[j]-2]+2 == i) {
                        matrix[j][nucleotides_size[j]-1] = -1;
                        matrix[j][nucleotides_size[j]++] = i;
                        flag[j] = true;
                    }
                    else
                        matrix[j][nucleotides_size[j]++] = i;
                }
                else
                    matrix[j][nucleotides_size[j]-1] = i;
            }
            else {
                flag[j] = false;
                matrix[j][nucleotides_size[j]++] = i;
            }
        }

        final int M = P.length;
        int[] A = new int[M];

        for (int i = 0; i < M; i++)
            for (int j = 0; j < nucleotides; j++)
                for (int k = 0; k < nucleotides_size[j]; k++) {
                    if (matrix[j][k] != -1) {
                        if (matrix[j][k] >= P[i]) {
                            if (matrix[j][k] <= Q[i]) {
                                A[i] = j + 1;
                                j = nucleotides;
                            }
                            break;
                        }
                    }
                    else {
                        if (matrix[j][k+1] >= P[i] && matrix[j][k+1] <= Q[i]) {
                            A[i] = j + 1;
                            j = nucleotides;
                            break;
                        }
                        else if (P[i] >= matrix[j][k-1] && P[i] <= matrix[j][k+1]) {
                            A[i] = j + 1;
                            j = nucleotides;
                            break;
                        }
                        k++;
                    }
                }
        return A;
    }
}
