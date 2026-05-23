import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class CountNo {

	//@ requires code != 0;
	//@ requires l <= m;
	//@ requires b >= 0;
	//@ ensures (\result == -1) || (l <= \result && \result <= m);
 
 
 
	public static int countNo(int code, int b, int l, int m) {
		int ret = 0;
		//@ maintaining l <= c && c <= m + 1;
		//@ maintaining 0 <= ret;
 
		//@ decreases m - c + 1;
		for (int c = l; c <= m; c++) {
			if (c % code != 0) {
				ret++;
			}
			if (ret == b) {
				return c;
			}
		}
		return -1;
	}
}
