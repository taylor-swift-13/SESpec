import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindMaxVal {

    /*@
      requires value >= 0;
      requires p > 0;
      requires 0 <= z && z < p;
      ensures 0 <= \result && \result <= value;
      // The following two ensures characterize the maximal k in 1..value with k%p==z
      // using arithmetic (avoiding heavy quantifiers). The normalized remainder
      // ((value - z) % p + p) % p is the distance from `value` down to the largest
      // number <= value congruent to z. If that computed number is < 1 then no
      // such k exists and result is 0.
      ensures (\result == 0) <==> (value - (((value - z) % p + p) % p) < 1);
      ensures (\result == 0) || \result == value - (((value - z) % p + p) % p);
    @*/
	public static int findMaxVal(int value, int p, int z) {
		int result = 0;
		/*@
		  maintaining 1 <= c && c <= value + 1;
		  maintaining 0 <= result && result <= value;
		  // If result is non-zero it always satisfies the congruence z (observed so far).
		  maintaining (result == 0) || (result % p == z);
		  decreases value - c + 1;
		@*/
		for (int c = 1; c <= value; c++) {
			if ((c % p) == z) {
				result = c;
			}
		}
		return result;
	}
}