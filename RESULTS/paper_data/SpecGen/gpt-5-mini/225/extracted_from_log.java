import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindMissing {

	//@ requires args != null;
	//@ requires 0 <= array && array <= args.length;
	//@ ensures (array == 0 || array == 1) ==> \result == 1;
	//@ ensures array >= 1 ==> 1 <= \result && \result <= array;
 
	//@ ensures (\result < array) ==> args[\result - 1] != \result;
 
	public /*@ spec_public @*/ static int findMissing(int[] args, int array) {
		int find = 1;
		if (array == 0 || array == 1) {
			return find;
		}
		//@ maintaining 1 <= remaining && remaining <= array + 1;
 
		//@ maintaining (remaining == 1 ? find == 1 : find == remaining - 1);
		//@ decreases array - remaining + 1;
		for (int remaining = 1; remaining <= array; remaining++) {
			if (args[remaining - 1] == remaining) {
				find = remaining;
			} else if (args[remaining - 1] != remaining) {
				return remaining;
			}
		}
		return find;
	}
}