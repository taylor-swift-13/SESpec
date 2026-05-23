import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class MaxSubArraySum {

    //@ requires a != null && size > 0 && size <= a.length;
    //@ ensures \result >= 0 && \result <= size;
    //@ ensures (\exists int i, j; 0 <= i && i <= j && j < size; \result == j - i + 1 && (\sum int m; i <= m && m <= j; a[m]) == (\max int x, y; 0 <= x && x <= y && y < size; (\sum int n; x <= n && n <= y; a[n])));
    public static int maxSubArraySum(int[] a, int size) {
        int max_so_far = 0;
        int max_ending_here = 0;
        int start = 0;
        int end = 0;
        int s = 0;

        //@ maintaining 0 <= i && i <= size;
        //@ maintaining 0 <= start && start <= end && end < size;
        //@ maintaining (\forall int x, y; 0 <= x && x <= y && y < i; (\sum int m; x <= m && m <= y; a[m]) <= max_so_far);
        //@ maintaining max_ending_here >= 0;
        //@ decreases size - i;
        for (int i = 0; i < size; i++) {
            max_ending_here += a[i];
            if (max_so_far < max_ending_here) {
                max_so_far = max_ending_here;
                start = s;
                end = i;
            }
            if (max_ending_here < 0) {
                max_ending_here = 0;
                s = i + 1;
            }
        }
        return end - start + 1;
    }
}