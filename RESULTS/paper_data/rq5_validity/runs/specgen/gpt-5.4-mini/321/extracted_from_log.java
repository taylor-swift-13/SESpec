import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class Lcm {

	//@ requires n > 0 && y > 0;
	//@ ensures \result >= 0;  
 
	//@ ensures (\forall int d; d > 0 && n % d == 0 && y % d == 0; d - 1 <= \result);  
	public static int lcm(int n, int y) {
		int ret = 1;
		int r = 1;
		if (n > y) {
			int g = n;
			n = y;
			y = g;
		}
		//@ maintaining 1 <= l && l <= n + 1;
		//@ maintaining ret > 0;
		//@ maintaining (\forall int d; 1 <= d && d < l && n % d == 0 && y % d == 0; d <= ret);
		//@ decreases n - l + 1;
		for (int l = 1; l <= n; l++) {
			if (n % l == 0 && y % l == 0) {
				ret = l;
			}
		}
		r = (n * y) / ret;
		return r;
	}
}