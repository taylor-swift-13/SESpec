import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class GetPell {

	/*@ 
	  @ requires seed >= 1;
	  @ 
	  @ // Base case
	  @ ensures seed == 1 ==> \result == 1;
	  @ 
	  @ // Recursive specification: for seed >= 2 the result satisfies the Pell recurrence modulo 1e9
	  @ ensures seed >= 2 ==> \result == (2 * getPell(seed - 1) + getPell(seed - 2)) % 1000000000;
	  @ 
	  @ // Result is in the modular range
	  @ ensures 0 <= \result && \result < 1000000000;
	  @*/
	public static int getPell(int seed) {
		int[] arr = new int[seed + 1];
		arr[0] = 0;
		arr[1] = 1;
		/*@ 
		  @ // Loop invariant: for all indices < p the array stores Pell numbers modulo 1e9
		  @ maintaining 2 <= p && p <= seed + 1;
		  @ maintaining arr[0] == 0;
		  @ maintaining arr[1] == 1;
		  @ maintaining (\forall int k; 2 <= k && k < p; arr[k] == (2 * arr[k-1] + arr[k-2]) % 1000000000);
		  @ maintaining (\forall int k; 0 <= k && k < p; 0 <= arr[k] && arr[k] < 1000000000);
		  @ decreases seed - p + 1;
		  @*/
		for (int p = 2; p <= seed; p++) {
			arr[p] = (2 * arr[p - 1]
					+ arr[p - 2]) % 1000000000;
		}
		return arr[seed];
	}
}