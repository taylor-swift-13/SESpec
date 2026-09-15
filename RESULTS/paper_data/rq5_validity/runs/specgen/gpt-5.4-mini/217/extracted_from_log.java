import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class Last {

	//@ requires args != null;
	//@ requires 0 <= y && y <= args.length;
	//@ ensures \result == -1 || (\result >= 0 && \result < y && args[\result] == x);
 
	public static int last(int[] args, int x, int y) {
		int i = 0;
		int r = y - 1;
		int k = -1;

		//@ maintaining 0 <= i && i <= y;
		//@ maintaining -1 <= r && r < y;
		//@ maintaining -1 <= k && k < y;
		//@ maintaining k == -1 || args[k] == x;
		//@ decreases r - i + 1;
		while (i <= r) {
			int tmp = (i + r) / 2;
			if (args[tmp] == x) {
				k = tmp;
				i = tmp + 1;
			} else if (args[tmp] < x) {
				i = tmp + 1;
			} else {
				r = tmp - 1;
			}
		}

		return k;
	}
}