import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindFixedPoint {

	//@ requires args != null;
	//@ requires array >= 0 && array <= args.length;
	//@ ensures (\result == -1) || (0 <= \result && \result < array && args[\result] == \result);
	public static int findFixedPoint(int[] args, int array) {
		int i = 0;
		int stop = array - 1;
		//@ maintaining 0 <= i && i <= array;
		//@ maintaining -1 <= stop && stop < array;
 
 
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