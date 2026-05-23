import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FirstMissingPositive {

	//@ requires args != null;
	//@ requires 0 <= array && array <= args.length;
	//@ ensures 1 <= \result && \result <= array + 1;
	//@ ensures (\forall int k; 1 <= k && k < \result; (\forall int i; 0 <= i && i < array; \old(args[i]) == k));  
	public static int firstMissingPositive(int[] args, int array) {
		int ret = 0;
		//@ maintaining 0 <= ret && ret <= array;
		//@ decreases array - ret;
		while (ret < array) {
			if (args[ret] <= 0 || args[ret] > array
					|| args[ret] == ret + 1) {
				ret++;
			} else {
				int j = args[ret];
				args[ret] = args[j - 1];
				args[j - 1] = j;
			}
		}
		//@ maintaining 0 <= ret && ret <= array;
		//@ maintaining (\forall int i; 0 <= i && i < ret; args[i] == i + 1);
		//@ decreases array - ret;
		for (ret = 0; ret < array; ret++) {
			if (args[ret] != ret + 1) {
				return ret + 1;
			}
		}
		return array + 1;
	}
}