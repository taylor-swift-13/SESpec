import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class Lcm {

	//@ requires n > 0 && y > 0;
	//@ ensures \result >= 0;  
	public static int lcm(int n, int y) {
		int ret = 1;
		int g = 1;
		if (n > y) {
			int r = n;
			n = y;
			y = r;
		}
		//@ maintaining 1 <= l && l <= n + 1;
		//@ maintaining ret >= 1;
		//@ decreasing n - l + 1;
		for (int l = 1; l <= n; l++) {
			if (n % l == 0 && y % l == 0) {
				ret = l;
			}
		}
		g = (n * y) / ret;
		return g;
	}
}