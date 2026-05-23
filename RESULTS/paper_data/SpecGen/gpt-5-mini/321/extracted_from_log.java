import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class Lcm {

	//@ requires n >= 1 && y >= 1;
 
	public static int lcm(int n, int y) {
		int ret = 1;
		int r = 1;
		if (n > y) {
			int g = n;
			n = y;
			y = g;
		}
		//@ maintaining 1 <= l && l <= n + 1;
		//@ maintaining 1 <= ret && ret <= n;
		//@ decreases n - l;
		for (int l = 1; l <= n; l++) {
			if (n % l == 0 && y % l == 0) {
				ret = l;
			}
		}
		r = (n * y) / ret;
		return r;
	}
}