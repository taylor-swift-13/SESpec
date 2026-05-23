import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class MaxSubArraySum {

	/*@ 
	  @ requires a != null;
	  @ requires array > 0 && array <= a.length;
	  @ 
 
	  @ 
	  @ // The result is the length of some subarray [i..j] (0-based, j < array)
	  @ // whose sum is maximal among all subarrays within a[0..array-1].
	  @ ensures (\exists int i, j; 0 < i && i < j || j < array &&  
	  @            j - i + 1 == \result &&
	  @            (\forall int u, v; 0 <= u && u <= v && v < array ==>
	  @                (\sum int k; i <= k && k <= j; a[k]) >= (\sum int k; u <= k && k <= v; a[k]))
	  @         );
	  @*/
	public static int maxSubArraySum(int[] a, int array) {
		int max_so_far = 0;
		int max_ending_here = 0;
		int max = 0;
		int stop = 0;
		int count = 0;

		/*@ 
		  @ // Loop invariants that hold at the head of each iteration
		  @ maintaining 0 <= n && n <= array;
		  @ maintaining 0 <= count && count <= n+1;
		  @ maintaining 0 <= max && max <= n;
		  @ maintaining 0 <= stop && stop <= n;
		  @ maintaining max_so_far >= 0;
		  @ maintaining max_ending_here >= 0;
		  @ decreases array - n;
		  @*/
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