import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindLucas {

	/*@ 
	  @ // Recursive mathematical definition of the Lucas sequence used in the specifications.
	  @ // L(0) = 2, L(1) = 1, L(n) = L(n-1) + L(n-2) for n >= 2.
	  @ logic int L(int n) = (n == 0) ? 2 : (n == 1) ? 1 : L(n-1) + L(n-2);
	  @*/

	/*@ 
	  @ requires seed >= 1; // method as written accesses result[1], so seed must be >= 1
	  @ ensures \result == L(seed);
	  @*/
	public static int findLucas(int seed) {
		int[] result = new int[seed + 1];
		result[0] = 2;
		result[1] = 1;
		/*@
		  @ // loop invariant: c ranges between 2 and seed+1 during the loop,
		  @ // and for all indices i < c the array holds the correct Lucas value L(i).
		  @ maintaining 2 <= c && c <= seed + 1;
		  @ maintaining (\forall int i; 0 <= i && i < c; result[i] == L(i));
		  @ decreases seed - c + 1;
		  @*/
		for (int c = 2; c <= seed; c++) {
			result[c] = result[c - 1]
					+ result[c - 2];
		}
		return result[seed];
	}
}