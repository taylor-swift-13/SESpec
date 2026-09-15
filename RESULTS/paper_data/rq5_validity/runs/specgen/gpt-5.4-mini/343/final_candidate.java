import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class CountNo {

	//@ requires code != 0;
	//@ requires 0 <= b;
	//@ requires l <= c;
	//@ ensures (\result == -1) || (l <= \result && \result <= c);
 
	public static int countNo(int code, int b, int l, int c) {
		int ret = 0;
		//@ maintaining l <= loop && loop <= c + 1;
 
 
		//@ decreases c - loop + 1;
		for (int loop = l; loop <= c; loop++) {
			if (loop % code != 0) {
				ret++;
			}
			if (ret == b) {
				return loop;
			}
		}
		return -1;
	}
}
