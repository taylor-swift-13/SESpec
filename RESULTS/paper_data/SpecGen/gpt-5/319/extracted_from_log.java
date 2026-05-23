import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class Lcm {

	//@ requires n >= 0 && y >= 0;
	//@ ensures \result >= 0;
	//@ ensures (\old(n) == 0 || \old(y) == 0) ==> (\result == 0);
	//@ ensures (\old(n) > 0 && \old(y) > 0) ==> (\result > 0);
	public static int lcm(int n, int y) {
		int ret = 1;
		int l = 1;
		if (n > y) {
			int g = n;
			n = y;
			y = g;
		}
		//@ maintaining 1 <= j && j <= n + 1;
		//@ maintaining ret >= 1 && ret <= j && ret <= n;
		//@ maintaining n >= 0 && y >= 0;
		//@ decreases n - j + 1;
		for (int j = 1; j <= n; j++) {
			if (n % j == 0 && y % j == 0) {
				ret = j;
			}
		}
		//@ assert ret >= 1;
		//@ assume (long)n * (long)y <= Integer.MAX_VALUE;
		l = (n * y) / ret;
		return l;
	}
}