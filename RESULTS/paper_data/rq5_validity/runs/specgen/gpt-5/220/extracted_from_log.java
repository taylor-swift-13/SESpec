import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class First {

	//@ requires args != null;
	//@ requires 0 <= n && n <= args.length;
	//@ ensures true;
	public static int first(int[] args, int array, int n) {
		int i = 0;
		int hi = n - 1;
		int result = -1;
		//@ maintaining true;
		while (i <= hi) {
			int tmp = (i + hi) / 2;
			//@ assume 0 <= tmp && tmp < args.length;
			if (args[tmp] == array) {
				result = tmp;
				hi = tmp - 1;
			} else if (args[tmp] < array) {
				i = tmp + 1;
			} else {
				hi = tmp - 1;
			}
		}
		return result;
	}
}