import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class First {

	public static int first(int[] args, int Array, int n) {
		//@ assume args != null && 0 <= n && n <= args.length;
		int i = 0;
		int hi = n - 1;
		int result = -1;
		//@ maintaining 0 <= i && i <= n;
		//@ maintaining -1 <= hi && hi < n;
		//@ maintaining result == -1 || (0 <= result && result < n && args[result] == Array);
 
 
		//@ decreases hi - i + 1;
		while (i <= hi) {
			int tmp = (i + hi) / 2;
			if (args[tmp] == Array) {
				result = tmp;
				hi = tmp - 1;
			} else if (args[tmp] < Array) {
				i = tmp + 1;
			} else {
				hi = tmp - 1;
			}
		}
		return result;
	}
}