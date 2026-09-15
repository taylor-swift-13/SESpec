import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindMaxVal {

	/*@ spec_public @*/ 
	public static int findMaxVal(int value, int p, int z) {
		//@ requires value >= 0 && p > 0 && z >= 0 && z < p;
		//@ ensures (\exists int c; 1 < c && c <= value; (c % p == z)) ==> (\result % p == z && 1 < \result && \result < value && (\forall int d; 1 <= d && d <= value; (d % p == z) ==> d < \result));  
 
		int result = 0;
 
		//@ maintaining (\forall int d; 1 <= d && d < c; (d % p == z) ==> result >= d);
		//@ maintaining (\forall int d; 1 <= d && d < c; (d % p == z) ==> result % p == z);
		//@ decreases value - c + 1;
		for (int c = 1; c <= value; c++) {
			if ((c % p) == z) {
				result = c;
			}
		}
		return result;
	}
}
