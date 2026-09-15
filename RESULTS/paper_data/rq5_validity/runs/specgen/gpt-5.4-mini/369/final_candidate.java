import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindMaxVal {

	//@ requires value >= 0;
	//@ requires p > 0;
	//@ ensures 0 <= \result && \result <= value;
	//@ ensures \result == 0 || ((\result % p) == dy);
	//@ ensures (\forall int c; 1 <= c && c <= value && (c % p) == dy; c <= \result);
	public static int findMaxVal(int value, int p, int dy) {
		int result = 0;
		//@ maintaining 0 <= result && result <= c;
		//@ maintaining (\forall int k; 1 < k && k < c && (k % p) == dy; k < result);  
		//@ maintaining (\forall int k; 1 <= k && k < c && (k % p) == dy; k <= result);
		//@ decreases value - c + 1;
		for (int c = 1; c <= value; c++) {
			if ((c % p) == dy) {
				result = c;
			}
		}
		return result;
	}
}
