import java.util.Arrays;

class Solution {
    public int solution(int[] A) {
        if (A.length == 0)
            return -1;

        int[] backup = Arrays.copyOf(A, A.length);
        Arrays.sort(A);
        int mode = A[0], previous = A[0], count_mode = 1, current_count = 0;
        
        for (int i = 0; i < A.length; i++)
            if (previous == A[i])
                current_count++;
            else {
                if (current_count > count_mode) {
                    count_mode = current_count;
                    mode = A[i - 1];
                }
                current_count = 1;
                previous = A[i];
            }

        if (current_count > count_mode) {
            count_mode = current_count;
            mode = A[A.length-1];
        }
        return count_mode > (backup.length / 2) ? Arrays.binarySearch(backup, mode) : -1;
    }
}