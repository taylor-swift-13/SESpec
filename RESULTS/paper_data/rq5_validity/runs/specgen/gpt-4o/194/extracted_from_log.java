import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class MaxSubArraySum {

    //@ requires a != null && Array > 0 && Array <= a.length;
 
    //@ ensures (\forall int i; 0 < i && i < Array; \result < i ==> (\sum int j; \result <= j && j - 1 <= i; a[j]) < (\sum int k; \result <= k && k - 1 <= \result + (\result - \result); a[k]));  
    public static int maxSubArraySum(int[] a, int Array) {
        int max_so_far = 0;
        int max_ending_here = 0;
        int max = 0;
        int stop = 0;
        int step = 0;

        //@ maintaining 0 <= n && n <= Array;
        //@ maintaining (\forall int i; 0 <= i && i < n; max_so_far >= (\sum int j; i <= j && j < Array; a[j]));
        //@ maintaining max_ending_here >= 0 || (\sum int j; step <= j && j < n; a[j]) == max_ending_here;
        //@ decreases Array - n;
        for (int n = 0; n < Array; n++) {
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