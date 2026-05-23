import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class GetGcd {

	//@ requires arg != null && arg.length > 0;
	//@ assignable \nothing;
	//@ ensures \result >= 0;
	//@ ensures \result == 0 || (\exists int t; 0 <= t && t < arg.length; \result == arg[t]);
	public static int getGcd(int[] arg) {
		int g = 0;
		int ret = arg[0];
		//@ maintaining 1 <= j && j <= arg.length;
		//@ maintaining (\exists int k; 0 <= k && k < j; ret == arg[k]);
		//@ maintaining (\forall int k; 0 <= k && k < j; ret <= arg[k]);
		//@ maintaining g >= 0;
		//@ maintaining g == 0 || (\exists int k; 0 <= k && k < j; g == arg[k]);
		//@ maintaining (\forall int i; 0 <= i && i < arg.length; arg[i] == \old(arg[i]));
		//@ decreases arg.length - j;
		for (int j = 1; j < arg.length; j++) {
			if (arg[j] > ret) {
				g = g > ret ? g : ret;
			} else {
				ret = arg[j];
			}
		}
		return g;
	}
}