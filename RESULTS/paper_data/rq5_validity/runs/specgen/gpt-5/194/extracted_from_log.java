import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class MaxSubArraySum {

	//@ requires a != null;
	//@ requires 1 <= Array && Array <= a.length;
	//@ assignable \nothing;
	//@ ensures 1 <= \result && \result <= Array;
	//@ ensures (\forall int k; 0 <= k && k < Array; a[k] < 0) ==> \result == 1;
	public static int maxSubArraySum(int[] a, int Array) {
		int max_so_far = 0;
		int max_ending_here = 0;
		int max = 0;
		int stop = 0;
		int step = 0;

		//@ maintaining 0 <= n && n <= Array;
		//@ maintaining 0 <= max_ending_here && 0 <= max_so_far && max_so_far >= max_ending_here;
		//@ maintaining 0 <= step && step <= n + 1;
		//@ maintaining 0 <= max && max <= stop && stop <= n;
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