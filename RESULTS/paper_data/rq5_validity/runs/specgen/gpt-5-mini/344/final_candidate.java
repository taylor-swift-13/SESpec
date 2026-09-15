import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class CountNo {

	/*@ 
	  @ requires code != 0;
	  @ requires b > 0;
	  @ requires l <= m;
	  @ 
	  @ // If result is -1 then there are fewer than b integers in [l,m] not divisible by code
 
	  @ 
	  @ // If result is not -1 then it is the b-th integer in [l,m] that is not divisible by code
 
	  @   (l <= \result && \result <= m && \result % code != 0 &&
	  @    (\num_of int i; l <= i && i <= \result && i % code != 0) == b);
	  @*/
	public static int countNo(int code, int b, int l, int m) {
		int ret = 0;
		/*@ 
		  @ // c iterates from l to m (c is the loop index)
		  @ maintaining l <= c && c <= m + 1;
		  @ // ret counts number of non-divisible values seen so far in [l, c-1]
		  @ maintaining 0 <= ret && ret <= b;
 
		  @ decreases m - c + 1;
		  @*/
		for (int c = l; c <= m; c++) {
			if (c % code != 0) {
				ret++;
			}
			if (ret == b) {
				return c;
			}
		}
		return -1;
	}
}
