import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindMaxVal {

    //@ requires k != 0;
    //@ requires value >= 0;
    //@ ensures 0 <= \result && \result <= value;
    //@ ensures \result == 0 || (\result % k) == z;
	public static int findMaxVal(int value, int k, int z) {
		int result = 0;
        //@ maintaining 1 <= c && c <= value + 1;
        //@ maintaining 0 <= result && result < c;
        //@ maintaining result == 0 || (result % k) == z;
        //@ decreases value - c + 1;
		for (int c = 1; c <= value; c++) {
			if ((c % k) == z) {
				result = c;
			}
		}
		return result;
	}
}