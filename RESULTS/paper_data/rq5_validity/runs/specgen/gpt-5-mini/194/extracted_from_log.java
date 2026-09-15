import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class MaxSubArraySum {

	/*@ 
	  @ requires a != null;
	  @ requires Array > 0 && Array <= a.length;
	  @ ensures 0 <= \result && \result <= Array;
	  @ ensures (\exists int i, j; 0 <= i && i <= j && j < Array &&
	  @            \result == j - i + 1 &&
	  @            (\forall int p, q; 0 <= p && p <= q && q < Array ==>
	  @                (\sum int k; i <= k && k <= j; a[k]) >= (\sum int k; p <= k && k <= q; a[k])
	  @            )
	  @         );
	  @*/
	public static int maxSubArraySum(int[] a, int Array) {
		int max_so_far = 0;
		int max_ending_here = 0;
		int max = 0;
		int stop = 0;
		int step = 0;

		/*@ 
 
 
 
 
 
		  @               (\exists int i, j; 0 <= i && i <= j && j < n &&
		  @                    max_so_far == (\sum int k; i <= k && k <= j; a[k]) &&
		  @                    max == i && stop == j
		  @               )
		  @           );
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
		return stop - max + 1;
	}
}