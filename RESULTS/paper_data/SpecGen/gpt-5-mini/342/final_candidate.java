import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class CountNo {

	/*@ 
	  @ requires code != 0;
	  @ requires b >= 0;
	  @ requires l <= m;
	  @ 
	  @ // If result is -1 then there are fewer than b numbers in [l..m] not divisible by code
 
	  @ 
	  @ // If result is not -1 then it is the first c in [l..m] such that the count of numbers
	  @ // in [l..result] not divisible by code equals b; in particular result itself is not
	  @ // divisible by code.
 
	  @           (l <= \result && \result <= m &&
	  @            \result % code != 0 &&
	  @            (\num_of int k; l <= k && k <= \result; k % code != 0) == b &&
	  @            (\forall int t; l <= t && t < \result; (\num_of int k; l <= k && k <= t; k % code != 0) < b));
	  @ 
 
	  @*/
	public static int countNo(int code, int b, int l, int m) {
		int result = 0;
		/*@ 
		  @ maintaining l <= c && c <= m + 1;
 
		  @ maintaining 0 <= result && result <= c - l;
		  @ decreases m - c + 1;
		  @*/
		for (int c = l; c <= m; c++) {
			if (c % code != 0) {
				result++;
			}
			if (result == b) {
				return c;
			}
		}
		return -1;
	}
}
