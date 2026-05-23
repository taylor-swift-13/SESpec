import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class EvenBinomialCoeffSum {

	/*@
	  @ requires 0 <= seed && seed <= 31;
	  @ ensures seed == 0 ==> \result == 1;
	  @ ensures seed > 0  ==> \result == (1 << (seed - 1));
	  @*/
	public static int evenBinomialCoeffSum(int seed) {
		int result = 0;
		int[] arr = new int[seed + 1];
		arr[0] = 1;
		/*@
		  @ maintaining arr.length == seed + 1;
		  @ maintaining arr[0] == 1;
		  @ maintaining 1 <= d && d <= seed + 1;
		  @ maintaining (\forall int k; 1 <= k && k < d; arr[k] == (1 << (k - 1)));
		  @ decreases seed - d + 1;
		  @*/
		for (int d = 1; d <= seed; d++) {
			/*@
			  @ maintaining arr.length == seed + 1;
			  @ maintaining arr[0] == 1;
			  @ maintaining 0 <= c && c <= d;
			  @ maintaining (\forall int k; 1 <= k && k < d; arr[k] == (1 << (k - 1)));
			  @ maintaining (c == 0 ==> arr[d] == 0) && (c > 0 ==> arr[d] == (1 << (c - 1)));
			  @ decreases d - c;
			  @*/
			for (int c = 0; c < d; c++) {
				arr[d] = arr[d] + arr[c];
			}
		}
		return arr[seed];
	}
}