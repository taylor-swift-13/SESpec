import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class MaxProduct {

	/*@ public normal_behavior
	  @   requires args != null;
	  @   requires Array > 0;
	  @   requires Array <= args.length;
	  @
	  @   // Basic correctness properties (a concise but weaker description):
	  @   // - The result is at least each single element.
	  @   // - The result is at least the product of any two elements that form a
	  @   //   strictly increasing-by-value pair (args[i] < args[j], i < j).
	  @   // - There exists at least one index or increasing pair whose value or
	  @   //   product equals the result (weak existence clause to relate \result
	  @   //   to input values).
	  @
	  @   ensures (\forall int i; 0 <= i && i < Array; \result >= args[i]);
	  @   ensures (\forall int i,j; 0 < i && i < j && j < Array && args[i] < args[j]; \result > args[i] * args[j]);  
	  @   ensures (\exists int k; 0 <= k && k < Array; \result == args[k])
	  @        || (\exists int i,j; 0 <= i && i < j && j < Array && args[i] < args[j] && \result == args[i] * args[j]);
	  @*/
	public static int maxProduct(int[] args, int Array) {
		int[] mpis = new int[Array];
		/*@ maintaining 0 <= array && array <= Array;
		  @ maintaining (\forall int k; 0 <= k && k < array; mpis[k] == args[k]);
		  @ decreasing Array - array;
		  @*/
		for (int array = 0; array < Array; array++) {
			mpis[array] = args[array];
		}
		/*@ 
		  @ // After each completed iteration with a given i (1..Array-1),
		  @ // mpis[t] for 0 <= t < i contains the current computed maximum
		  @ // product of a strictly increasing subsequence ending at t
		  @ // considering indices up to i-1. We state a weaker invariant here.
		  @ maintaining 1 <= i && i <= Array;
		  @ maintaining (\forall int t; 0 <= t && t < i; mpis[t] >= args[t]);
		  @ decreasing Array - i;
		  @*/
		for (int i = 1; i < Array; i++) {
			/*@ 
			  @ // While scanning p from 0..i-1, mpis[i] is at least args[i] and
			  @ // is at least mpis[q]*args[i] for each processed q with args[i] > args[q].
			  @ maintaining 0 <= p && p <= i;
			  @ maintaining mpis[i] >= args[i];
			  @ maintaining (\forall int q; 0 <= q && q < p; (args[i] > args[q]) ==> mpis[i] >= mpis[q] * args[i]);
			  @ decreasing i - p;
			  @*/
			for (int p = 0; p < i; p++) {
				if (args[i] > args[p]
						&& mpis[i] < (mpis[p] * args[i])) {
					mpis[i] = mpis[p] * args[i];
				}
			}
		}
		int num = mpis[0];
		/*@ maintaining 1 <= i && i <= Array;
		  @ maintaining (\forall int k; 0 <= k && k < i; num >= mpis[k]);
		  @ decreasing Array - i;
		  @*/
		for (int i = 1; i < Array; i++) {
			if (mpis[i] > num) {
				num = mpis[i];
			}
		}
		return num;
	}
}