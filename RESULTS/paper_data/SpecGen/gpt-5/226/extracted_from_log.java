import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindMissing {

	//@ requires args != null;
	//@ requires 0 <= array && array <= args.length;
	//@ ensures (array == 0 || array == 1) ==> \result == 1;
	//@ ensures (array >= 2 && (\forall int t; 1 <= t && t <= array; args[t-1] == t)) ==> \result == array;
	//@ ensures (array >= 2 && (\exists int k; 1 <= k && k <= array; args[k-1] != k))
	//@          ==> (1 <= \result && \result <= array
	//@               && args[\result-1] != \result
	//@               && (\forall int t; 1 <= t && t < \result; args[t-1] == t));
	//@ ensures (array >= 2) ==> (1 <= \result && \result <= array);
	public static int findMissing(int[] args, int array) {
		int found = 1;
		if (array == 0 || array == 1) {
			return found;
		}
		//@ maintaining 1 <= remaining && remaining <= array;
		//@ maintaining (\forall int t; 1 <= t && t < remaining; args[t-1] == t);
		//@ decreases array - remaining + 1;
		for (int remaining = 1; remaining <= array; remaining++) {
			if (args[remaining - 1] == remaining) {
				found = remaining;
			} else if (args[remaining - 1] != remaining) {
				return remaining;
			}
		}
		return found;
	}
}