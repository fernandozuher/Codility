import java.lang.Math;
class Solution {
    public int solution(int[] A) {
        int result = -2147483648;
        for (int i = 0, N = A.length; i < N; i++)
            for (int j = i, sum = 0; j < N; sum += A[j++], result = Math.max(sum, result));
        return result;
    }
}