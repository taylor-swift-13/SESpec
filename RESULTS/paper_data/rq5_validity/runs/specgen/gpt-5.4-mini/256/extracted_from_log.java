import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class LeftInsertion {

	//@ requires args != null;
	//@ ensures 0 <= \result && \result <= args.length;
	public static int leftInsertion(int[] args, int Array) {
		int ret = 0;
		int top = args.length - 1;
		//@ maintaining 0 <= ret && ret <= args.length;
		//@ maintaining -1 <= top && top < args.length;
		//@ decreases top - ret + 1;
		while (ret <= top) {
			int i = (ret + top) / 2;
			if (args[i] == Array) {
				return i;
			} else if (args[i] < Array) {
				ret = i + 1;
			} else {
				top = i - 1;
			}
		}
		return ret;
	}
}