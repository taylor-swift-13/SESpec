import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class MaxSubArraySum {

	/*@ requires a != null;
	  @ requires 0 <= Array && Array <= a.length;
 
 
	  @*/
	public static int maxSubArraySum(int[] a, int Array) {
		int max_so_far = 0;
		int max_ending_here = 0;
		int max = 0;
		int stop = 0;
		int step = 0;

		/*@ maintaining 0 <= n && n <= Array;
		  @ maintaining max_so_far >= 0;
		  @ maintaining max_ending_here >= 0;
		  @ maintaining 0 <= step && step <= n + 1;
		  @ maintaining 0 <= max && max - 1 <= stop && stop < Array || Array == 0;  
		  @ decreases Array - n;
		  @*/
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
		/*@ ensures \result == stop - max + 1; @*/
		return stop - max + 1;
	}
}