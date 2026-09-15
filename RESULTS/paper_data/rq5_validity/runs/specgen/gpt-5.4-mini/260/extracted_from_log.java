import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindFixedPoint {

	//@ requires args != null;
	//@ requires array >= 0 && array <= args.length;
	//@ ensures (\result == -1) || (0 <= \result && \result < array && args[\result] == \result);
 
	public static int findFixedPoint(int[] args, int array) {
		int ret = 0;
		int stop = array - 1;
		//@ maintaining 0 <= ret && ret <= array;
		//@ maintaining -1 <= stop && stop < array;
		//@ maintaining ret <= stop + 1;
		//@ decreases stop - ret + 1;
		while (ret <= stop) {
			int i = ret + (stop - ret) / 2;
			if (args[i] == i) {
				return i;
			} else if (args[i] < i) {
				ret = i + 1;
			} else {
				stop = i - 1;
			}
		}
		return -1;
	}
}