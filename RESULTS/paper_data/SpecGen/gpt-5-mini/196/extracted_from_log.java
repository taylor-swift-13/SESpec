import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class MaxSubArraySum {

	/*@ 
	  @ requires a != null;
	  @ requires 0 < array && array <= a.length;
	  @ 
	  @ // Result is a positive length not exceeding the given array prefix length
	  @ ensures 1 <= \result && \result <= array;
	  @ 
	  @ // There exists a subarray [i..j] within the prefix a[0..array-1] whose sum is
	  @ // non-negative, is maximal among all subarray sums inside that prefix, and
	  @ // the returned value equals its length j-i+1.
	  @ ensures (\exists int i; 0 <= i && i < array;
	  @            (\exists int j; i <= j && j < array &&
	  @              (\sum int k; i <= k && k <= j; a[k]) >= 0 &&
	  @              (\forall int i2, j2; 0 <= i2 && i2 <= j2 && j2 < array ==>
	  @                 (\sum int k; i2 <= k && k <= j2; a[k]) <= (\sum int k; i <= k && k <= j; a[k])
	  @              ) &&
	  @              \result == j - i + 1)));
	  @*/
	public static int maxSubArraySum(int[] a, int array) {
		int max_so_far = 0;
		int max_ending_here = 0;
		int max = 0;
		int stop = 0;
		int step = 0;

		/*@ 
		  @ // n is the loop index iterating over the prefix a[0..array-1]
		  @ maintaining 0 <= n && n <= array;
		  @ 
		  @ // max_so_far is always non-negative and is an upper bound on all subarray sums
		  @ // within the processed prefix a[0..n-1].
		  @ maintaining 0 <= max_so_far;
		  @ maintaining (\forall int i0, j0; 0 <= i0 && i0 <= j0 && j0 < n ==>
		  @                 (\sum int k; i0 <= k && k <= j0; a[k]) <= max_so_far);
		  @ 
		  @ // If we have processed at least one element, there exists a subarray achieving max_so_far
		  @ // inside the processed prefix, and its indices are recorded in (max, stop).
		  @ maintaining n > 0 ==> (\exists int i0, j0; 0 <= i0 && i0 <= j0 && j0 < n &&
		  @                            (\sum int k; i0 <= k && k <= j0; a[k]) == max_so_far &&
		  @                            i0 == max && j0 == stop);
		  @ 
		  @ // step is the start index of the current candidate subarray whose sum is max_ending_here,
		  @ // and max_ending_here equals the sum of a[step..n-1] (empty sum = 0 when step == n).
		  @ maintaining 0 <= step && step <= n;
		  @ maintaining max_ending_here == (\sum int k; step <= k && k <= n-1; a[k]);
		  @ 
		  @ // simple bounds on the integer variables
		  @ maintaining 0 <= max && 0 <= stop;
		  @ 
		  @ decreases array - n;
		  @*/
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