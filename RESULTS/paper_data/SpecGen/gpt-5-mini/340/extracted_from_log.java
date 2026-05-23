import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindDivisor {

	/*@
	  @ ensures 0 <= \result;
	  @ ensures \result <= (\old(z) < 0 ? -\old(z) : \old(z));
	  @ ensures (\old(z) == 0) ==> \result == 0;
	  @*/
	public static int findDivisor(int n, int z) {
		if (z < 0) {
			z = -z;
		}
		/*@ assert z >= 0; @*/
		int result = 0;
		/*@
		  @ // loop runs with loop in 1..z; result counts how many divisors were seen so far
		  @ maintaining 1 <= loop && loop <= z + 1;
		  @ maintaining 0 <= result && result <= loop - 1;
		  @ decreases z - loop + 1;
		  @*/
		for (int loop = 1; loop <= z; loop++) {
			if (n % loop == 0) {
				result = result + 1;
			}
		}
		return result;
	}
}