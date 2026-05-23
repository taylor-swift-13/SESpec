import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class First {

    //@ requires args != null;
    //@ requires 0 <= n && n <= args.length;
    //@ ensures -1 <= \result && \result < n;
    //@ ensures \result != -1 ==> args[\result] == array;
	public static int first(int[] args, int array, int n) {
		int ret = 0;
		int hi = n - 1;
		int result = -1;
        //@ maintaining 0 <= ret && ret <= n && -1 <= hi && hi < n;
        //@ maintaining ret <= hi + 1;
        //@ maintaining result == -1 || (0 <= result && result < n && args[result] == array);
        //@ decreases hi - ret + 1;
		while (ret <= hi) {
			int tmp = (ret + hi) / 2;
			if (args[tmp] == array) {
				result = tmp;
				hi = tmp - 1;
			} else if (args[tmp] < array) {
				ret = tmp + 1;
			} else {
				hi = tmp - 1;
			}
		}
		return result;
	}
}