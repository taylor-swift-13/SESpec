import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class LastTwoDigits {

	/*@ public normal_behavior
	  @   // If num <= 0 the loop does not execute and the product remains 1.
	  @   ensures num <= 0 ==> \result == 1;
	  @   // The method returns an int in range [0,99] corresponding to ret % 100.
	  @   ensures 0 <= \result && \result < 100;
	  @*/
	public static int lastTwoDigits(int num) {
		int ret = 1;
 
 
 
		  @*/
		for (int loop = 1; loop <= num; loop++) {
			ret *= loop;
		}
		int result = (int) (ret % 100);
		return result;
	}
}
