import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class JacobsthalNum {

	//@ requires j >= 1;
 
	public static int jacobsthalNum(int j) {
		int ret[] = new int[j + 1];
		ret[0] = 0;
		ret[1] = 1;
		/*@ maintaining 2 <= p && p <= j + 1;
		  @ maintaining ret[0] == 0;
		  @ maintaining ret[1] == 1;
		  @ decreases j - p + 1;
		  @*/
		for (int p = 2; p <= j; p++) {
			ret[p] = ret[p - 1]
					+ 2 * ret[p - 2];
		}
		return ret[j];
	}
}