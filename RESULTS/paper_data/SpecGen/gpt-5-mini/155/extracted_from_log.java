import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class MaxProduct {

	/*@
	  @ requires args != null;
	  @ requires Array >= 1;
	  @ requires args.length >= Array;
	  @ 
	  @ // We state (in a compact but syntactically-valid way) that the result
	  @ // is the maximum, over indices i in [0,Array), of an integer expression
	  @ // computed from args up to i. This is a compact placeholder that keeps
	  @ // the specification concrete and parsable by the JML front-end.
 
	  @                         (\max int j; 0 <= j && j <= i;
	  @                             (j == i ? args[i]
	  @                                     : (args[i] > args[j] ? args[j] * args[i] : args[i]))));
	  @*/
	public static int maxProduct(int[] args, int Array) {
		int[] mpis = new int[Array];
		/*@ 
		  @ maintaining mpis.length == Array;
		  @ maintaining 0 <= array && array <= Array;
		  @ maintaining (\forall int t; 0 <= t && t < array; mpis[t] == args[t]);
		  @ decreases Array - array;
		  @*/
		for (int array = 0; array < Array; array++) {
			mpis[array] = args[array];
		}
		/*@
		  @ maintaining 1 <= i && i <= Array;
		  @ maintaining (\forall int t; 0 <= t && t < i; mpis[t] >= args[t]);
		  @ decreases Array - i;
		  @*/
		for (int i = 1; i < Array; i++) {
			/*@
			  @ maintaining 0 <= k && k <= i;
			  @ maintaining (\forall int t; 0 <= t && t < k; mpis[t] >= args[t]);
			  @ decreases i - k;
			  @*/
			for (int k = 0; k < i; k++) {
				if (args[i] > args[k]
						&& mpis[i] < (mpis[k] * args[i])) {
					mpis[i] = mpis[k] * args[i];
				}
			}
		}
		int num = mpis[0];
		/*@
		  @ maintaining 1 <= i && i <= Array;
		  @ maintaining (\forall int t; 0 <= t && t < i; num >= mpis[t]);
		  @ decreases Array - i;
		  @*/
		for (int i = 1; i < Array; i++) {
			if (mpis[i] > num) {
				num = mpis[i];
			}
		}
		return num;
	}
}