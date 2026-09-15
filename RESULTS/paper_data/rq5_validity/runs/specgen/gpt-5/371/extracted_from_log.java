import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindMaxVal {

    //@ requires 0 <= value;
    //@ requires p != 0;
    //@ assignable \nothing;
    //@ ensures 0 <= \result && \result <= value;
    //@ ensures \result == 0 || \result % p == z;
	public static int findMaxVal(int value, int p, int z) {
		int result = 0;
        //@ maintaining 1 <= c && c <= value + 1;
        //@ maintaining 0 <= result && result < c;
        //@ maintaining result == 0 || result % p == z;
        //@ decreases value - c + 1;
		for (int c = 1; c <= value; c++) {
			if ((c % p) == z) {
				result = c;
			}
		}
		return result;
	}
}