import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class Lcm {

	/*@
	  @ requires n >= 0 && y >= 0;
	  @ // prevent overflow in the product n*y used in the computation
	  @ requires (y == 0) || (n <= Integer.MAX_VALUE / y);
	  @ // basic properties of the result
	  @ ensures (n == 0 || y == 0) ==> \result == 0;
	  @ ensures (n > 0 && y > 0) ==> \result > 0;
	  @ // result is a common multiple (using post-state n and y)
	  @ ensures (n == 0) || (\result % n == 0);
	  @ ensures (y == 0) || (\result % y == 0);
	  @ // simple bounds
	  @ ensures \result >= 0;
	  @ ensures \result <= n * y;
	  @ ensures \result >= n && \result >= y;
	  @*/
	public static int lcm(int n, int y) {
		int ret = 1;
		int r = 1;
		if (n > y) {
			int g = n;
			n = y;
			y = g;
		}
		/*@
		  @ maintaining 1 <= l && l <= n + 1;
		  @ maintaining 1 <= ret && ret <= l;
		  @ maintaining n % ret == 0 && y % ret == 0;
		  @ decreases n - l + 1;
		  @*/
		for (int l = 1; l <= n; l++) {
			if (n % l == 0 && y % l == 0) {
				ret = l;
			}
		}
		r = (n * y) / ret;
		return r;
	}
}