import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class CountNo {

	/*@
	  @ requires code != 0;
	  @ requires b >= 0;
	  @ requires l <= c;
	  @
	  @ // If there are fewer than b numbers in [l..c] that are not divisible by code, result is -1.
 
	  @
	  @ // Otherwise result is the smallest loop value in [l..c] such that the number of integers
	  @ // in [l..result] not divisible by code equals b.
 
	  @           (l <= \result && \result <= c &&
	  @            (\sum int i; l <= i && i <= \result; ((i % code != 0) ? 1 : 0)) == b &&
	  @            (\sum int i; l <= i && i < \result;  ((i % code != 0) ? 1 : 0)) == b - 1 &&
	  @            \result % code != 0);
	  @*/
	public static int countNo(int code, int b, int l, int c) {
		int ret = 0;
		/*@ maintaining l <= loop && loop <= c + 1;
 
		  @ decreases c - loop + 1;
		  @*/
		for (int loop = l; loop <= c; loop++) {
			if (loop % code != 0) {
				ret++;
			}
			if (ret == b) {
				return loop;
			}
		}
		return -1;
	}
}
