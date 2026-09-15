import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class Lcm {

	/*@ 
	  @ requires n > 0 && y > 0;
	  @ ensures \result > 0;
	  @ ensures \result % \old(n) == 0 && \result % \old(y) == 0;
	  @ ensures (\forall int z; z > 0 && z % \old(n) == 0 && z % \old(y) == 0 ==> \result <= z);
	  @*/
	public static int lcm(int n, int y) {
		int ret = 1;
		int g = 1;
		if (n > y) {
			int r = n;
			n = y;
			y = r;
		}
		/*@ 
		  @ // loop variable l ranges from 1..n
		  @ maintaining 1 <= l && l <= n + 1;
		  @ // ret is always a positive common divisor of n and y found so far
		  @ maintaining 1 <= ret && ret <= n && n % ret == 0 && y % ret == 0;
		  @ // ret is at least as large as any common divisor < l
		  @ maintaining (\forall int d; 1 <= d && d < l && d <= n ==> (n % d == 0 && y % d == 0) ==> d <= ret);
		  @ decreases n - l + 1;
		  @*/
		for (int l = 1; l <= n; l++) {
			if (n % l == 0 && y % l == 0) {
				ret = l;
			}
		}
		g = (n * y) / ret;
		return g;
	}
}