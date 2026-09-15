import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class MaxSubArraySum {

    //@ requires a != null;
    //@ requires array > 0 && array <= a.length;
    //@ ensures 1 <= \result && \result <= array;
    //@ ensures (\exists int i; 0 <= i && i < array; (\exists int j; i <= j && j < array; \result == j - i + 1));
	public static int maxSubArraySum(int[] a, int array) {
		int max_so_far = 0;
		int max_ending_here = 0;
		int max = 0;
		int stop = 0;
		int count = 0;

        //@ maintaining 0 <= n && n <= array;
        //@ maintaining 0 <= count && count <= n + 1 && count <= array;
        //@ maintaining 0 <= stop && stop <= n;
        //@ maintaining max_so_far >= 0;
        //@ maintaining max_ending_here >= 0;
        //@ maintaining (count <= n) ==> (max_ending_here == (\sum int t; count <= t && t <= n; a[t]));
        //@ maintaining max_so_far >= max_ending_here;
        //@ maintaining (max_so_far > 0) ==> (\exists int i; 0 <= i && i <= n; (\exists int s; i <= s && s <= n; (\sum int t; i <= t && t <= s; a[t]) == max_so_far));
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