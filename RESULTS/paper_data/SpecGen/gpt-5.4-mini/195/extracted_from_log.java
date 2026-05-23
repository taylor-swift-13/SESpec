import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class MaxSubArraySum {

	//@ requires a != null;
	//@ requires 0 <= array && array <= a.length;
	//@ ensures \result >= 0;
 
	//@ ensures (\exists int i; 0 <= i && i <= array; true);  
	public static int maxSubArraySum(int[] a, int array) {
		int max_so_far = 0;
		int max_ending_here = 0;
		int max = 0;
		int stop = 0;
		int count = 0;

		//@ maintaining 0 <= n && n <= array;
		//@ maintaining max_so_far >= 0;
		//@ maintaining max_ending_here >= 0;
		//@ maintaining 0 <= count && count <= n;
		//@ maintaining 0 <= max && max <= stop;
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