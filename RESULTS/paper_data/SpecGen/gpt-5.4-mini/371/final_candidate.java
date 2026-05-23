import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindMaxVal {

	//@ requires p > 0;
	//@ requires 0 <= z && z < p;
	//@ requires value >= 0;
	//@ ensures 0 <= \result && \result <= value;
	//@ ensures \result == 0 || (\result % p) == z;
 
	//@ ensures (\result != 0) ==> (\forall int c; \result < c && c - 1 <= value; (c % p) != z);  
	public static int findMaxVal(int value, int p, int z) {
		int result = 0;
		//@ maintaining 0 <= c && c <= value + 1;
		//@ maintaining 0 <= result && result <= c - 1;
		//@ maintaining result == 0 || (result % p) == z;
		//@ maintaining (\forall int k; 1 <= k && k < c; (k % p) != z ==> result != k);
		//@ decreases value - c + 1;
		for (int c = 1; c <= value; c++) {
			if ((c % p) == z) {
				result = c;
			}
		}
		return result;
	}
}
