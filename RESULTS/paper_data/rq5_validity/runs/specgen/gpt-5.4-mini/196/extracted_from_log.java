import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class MaxSubArraySum {

	//@ requires a != null;
	//@ requires 0 <= array && array <= a.length;
 
	//@ ensures \result - 1 <= array;  
	public static int maxSubArraySum(int[] a, int array) {
		int max_so_far = 0;
		int max_ending_here = 0;
		int max = 0;
		int stop = 0;
		int step = 0;

		//@ maintaining 0 <= n && n <= array;
		//@ maintaining 0 <= max_so_far;
		//@ maintaining 0 <= max_ending_here;
		//@ maintaining 0 <= max && max <= step && step <= n;
		//@ maintaining 0 <= stop && stop <= n;
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