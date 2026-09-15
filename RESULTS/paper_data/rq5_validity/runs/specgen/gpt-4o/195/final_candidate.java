import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class MaxSubArraySum {

    //@ requires a != null && array > 0 && array <= a.length;
    //@ ensures \result >= 0 && \result < array;
    //@ ensures (\exists int i, j; 0 <= i && i <= j && j < array; \result == i && (\forall int k; i <= k && k <= j; (\sum int t; i <= t && t <= j; a[t]) == (\max int u, v; 0 <= u && u <= v && v < array; (\sum int w; u <= w && w <= v; a[w]))));
    public static int maxSubArraySum(int[] a, int array) {
        int max_so_far = 0;
        int max_ending_here = 0;
        int max = 0;
        int stop = 0;
        int count = 0;

        //@ maintaining 0 <= n && n <= array;
        //@ maintaining max_so_far >= 0;
        //@ maintaining (\forall int i; 0 <= i && i < n; max_ending_here == (\sum int j; count <= j && j <= i; a[j]));
        //@ maintaining (\forall int i; 0 <= i && i < n; max_so_far >= max_ending_here);
        //@ decreases array - n;
        for (int n = 0; n < array; n++) {
            max_ending_here += a[n];
            if (max_so_far < max_ending_here) {
                max_so_far = max_ending_here;
                max = count;
                stop = n;
            }
            if (max_ending_here < 0) {
                max_ending_here = 0;
                count = n + 1;
            }
        }
        return stop - max + 1;
    }
}