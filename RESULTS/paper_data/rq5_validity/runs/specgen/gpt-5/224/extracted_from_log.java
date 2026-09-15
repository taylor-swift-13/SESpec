import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindMissing {

	//@ requires args != null;
	//@ requires array >= 0;
	//@ requires args.length >= array;
	//@ ensures (array == 0 || array == 1) ==> \result == 1;
	//@ ensures array >= 2 && \result < array ==> ((\forall int i; 1 <= i && i < \result; args[i-1] == i) && args[\result - 1] != \result);
	//@ ensures array >= 2 && \result == array ==> (\forall int i; 1 <= i && i <= array; args[i-1] == i);
	public static int findMissing(int[] args, int array) {
		int found = 1;
		if (array == 0 || array == 1) {
			return found;
		}
		//@ maintaining 1 <= num && num <= array + 1;
		//@ maintaining (\forall int i; 1 <= i && i < num; args[i-1] == i);
		//@ maintaining (num == 1 ==> found == 1) && (num > 1 ==> found == num - 1);
		//@ decreases array - num + 1;
		for (int num = 1; num <= array; num++) {
			if (args[num - 1] == num) {
				found = num;
			} else if (args[num - 1] != num) {
				return num;
			}
		}
		return found;
	}
}