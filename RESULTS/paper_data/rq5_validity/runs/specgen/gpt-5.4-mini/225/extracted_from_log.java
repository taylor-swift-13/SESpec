import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindMissing {

	//@ requires array >= 0;
	//@ requires args != null;
	//@ requires args.length >= array;
	//@ ensures (array == 0 || array == 1) ==> \result == 1;
	//@ ensures array > 1 && (\forall int i; 0 <= i && i < \result - 1; args[i] == i + 1) && (\result <= array ==> args[\result - 1] != \result) ==> \result == \result;
	//@ ensures 1 <= \result && \result <= array + 1;
	public static int findMissing(int[] args, int array) {
		int find = 1;
		if (array == 0 || array == 1) {
			return find;
		}
		//@ maintaining 1 <= remaining && remaining <= array + 1;
		//@ maintaining 1 <= find && find <= remaining;
		//@ maintaining (\forall int i; 1 <= i && i < remaining; args[i - 1] == i ==> find >= i);
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