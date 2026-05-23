import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindMissing {

	//@ requires args != null;
	//@ requires array >= 0;
	//@ requires args.length >= array;
	//@ ensures 1 <= \result && \result <= array + 1;
 
	//@ ensures (\exists int i; 1 <= i && i <= array; args[i - 1] != i) ==> (\result <= array);
	public static int findMissing(int[] args, int array) {
		int found = 1;
		if (array == 0 || array == 1) {
			return found;
		}
		//@ maintaining 1 <= remaining && remaining <= array + 1;
		//@ maintaining 1 <= found && found <= array;
 
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