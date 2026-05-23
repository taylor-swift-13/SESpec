import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindMaxVal {

	/*@
	  @ requires value >= 0;
	  @ requires p > 0;
	  @ requires 0 <= dy && dy < p;
	  @ ensures 0 <= \result && \result <= value;
 
 
	  @     (\forall int c; \result < c && c <= value ==> c % p != dy));
	  @*/
	public static int findMaxVal(int value, int p, int dy) {
		int result = 0;
		/*@
		  @ maintaining 1 <= c && c <= value + 1;
		  @ maintaining 0 <= result && result <= value;
		  @ decreases value - c + 1;
		  @*/
		for (int c = 1; c <= value; c++) {
			if ((c % p) == dy) {
				result = c;
			}
		}
		return result;
	}
}
