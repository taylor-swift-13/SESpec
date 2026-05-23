import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class Lcm {

	/*@ 
	  @ requires n > 0 && y > 0;
	  @ // there exists a greatest common divisor g of the original inputs such that result = (orig_n * orig_y) / g
 
	  @            1 <= g
	  @            && \old(n) % g == 0 && \old(y) % g == 0
	  @            && (\forall int d; 1 <= d && \old(n) % d == 0 && \old(y) % d == 0 ==> d <= g)
	  @            && \result == (\old(n) * \old(y)) / g);
	  @ ensures \result > 0;
	  @*/
	public static int lcm(int n, int y) {
		int ret = 1;
		int l = 1;
		if (n > y) {
			int g = n;
			n = y;
			y = g;
		}
		/*@
		  @ maintaining 1 <= ret && ret <= n && n % ret == 0 && y % ret == 0;
		  @ maintaining 1 <= j && j <= n + 1;
		  @ maintaining (\forall int d; 1 <= d && d <= j-1 && n % d == 0 && y % d == 0 ==> d <= ret);
		  @ decreases n - j + 1;
		  @*/
		for (int j = 1; j <= n; j++) {
			if (n % j == 0 && y % j == 0) {
				ret = j;
			}
		}
		l = (n * y) / ret;
		return l;
	}
}