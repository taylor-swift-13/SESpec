import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class BinomialCoeff {

	/*@ 
	  @ requires num >= 0 && p >= 0 && p <= num;
	  @ ensures \result >= 1;
	  @ ensures (\result == 1) <==> (\old(p) == 0 || \old(p) == \old(num));
	  @*/
	public static int binomialCoeff(int num, int p) {
		if (p > num - p)
			p = num - p;
		int b = 1;
		/*@ 
		  @ maintaining b + 1 >= 1;  
		  @ maintaining b <= Integer.MAX_VALUE;
		  @ decreases p - r + 1;
		  @*/
		for (int r = 1; r <= p; r++) {
			b = b * (num - r + 1) / r;
		}
		return b;
	}
}
