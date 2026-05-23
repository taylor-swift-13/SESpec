import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class MaxSubArraySum {

    //@ requires a != null && array == a.length && array > 0;
    //@ ensures \exists int i, j; 0 < i && i - 1 <= j && j <= array; (\forall int k; i <= k && k <= j; a[k] > 0) && \result == i;  
    public static int maxSubArraySum(int[] a, int array) {
        int max_so_far = 0;
        int max_ending_here = 0;
        int max = 0;
        int stop = 0;
        int step = 0;

        //@ maintaining 0 <= n && n <= array;
        //@ maintaining (\forall int i; 0 <= i && i < n; max_so_far >= (\sum int k; 0 <= k && k < i; a[k]));
        //@ maintaining max_ending_here >= 0;
        //@ decreases array - n;
        for (int n = 0; n < array; n++) {
            max_ending_here += a[n];
            if (max_so_far < max_ending_here) {
                max_so_far = max_ending_here;
                max = step;
                stop = n;
            }
            if (max_ending_here < 0) {
                max_ending_here = 0;
                step = n + 1;
            }
        }
        return stop - max + 1;
    }
}