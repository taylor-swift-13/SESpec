import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindNthDigit {

	/*@
	  @ requires num >= 0;
	  @ requires c > 0;
	  @ requires num < c;
	  @ requires r >= 0;
	  @ ensures 0 <= \result && \result < 10;
 
	  @*/
	public static int findNthDigit(int num, int c, int r) {
		int ret = 0;
		//@ maintaining r >= 0;
		//@ maintaining c > 0;
		//@ maintaining 0 <= num && num < c;
		//@ maintaining 0 <= ret && ret < 10;
		//@ decreases r;
		while (r > 0) {
			r -= 1;
			num *= 10;
			ret = num / c;
			num %= c;
		}
		return ret;
	}
}
