import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindFixedPoint {

	//@ requires args != null;
	//@ requires 0 <= array && array <= args.length;
	//@ requires (\forall int j; 0 <= j && j < array; \forall int i; 0 <= i && i < j; args[i] <= args[j]);
	//@ ensures \result == -1 <==> (\forall int k; 0 <= k && k < array; args[k] != k);
	//@ ensures 0 <= \result && \result < array ==> args[\result] == \result;
	public static int findFixedPoint(int[] args, int array) {
		int i = 0;
		int stop = array - 1;
		//@ maintaining 0 <= i && i <= array;
		//@ maintaining -1 <= stop && stop < array;
		//@ maintaining i <= stop + 1;
		//@ maintaining (\forall int k; 0 <= k && k < i; args[k] < k);
		//@ maintaining (\forall int k; stop < k && k < array; args[k] > k);
		//@ decreases stop - i + 1;
		while (i <= stop) {
			int cur = i + (stop - i) / 2;
			if (args[cur] == cur) {
				return cur;
			} else if (args[cur] < cur) {
				i = cur + 1;
			} else {
				stop = cur - 1;
			}
		}
		return -1;
	}
}