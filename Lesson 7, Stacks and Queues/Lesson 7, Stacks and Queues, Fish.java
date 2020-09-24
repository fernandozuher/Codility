import java.util.*;
class Solution {
    public int solution(int[] A, int[] B) {
        int i = 0, alive, N; alive = N = A.length;
        for (ArrayDeque<Integer> stack = new ArrayDeque<Integer>(); i < N; i++)
            if (B[i] == 1)
                stack.addLast(i);
            else if (!stack.isEmpty()) {
                alive--;
                if (A[stack.getLast()] < A[i]) {
                    stack.removeLast();
                    i--;
                }
            }
        return alive;
    }
}
// O(N)