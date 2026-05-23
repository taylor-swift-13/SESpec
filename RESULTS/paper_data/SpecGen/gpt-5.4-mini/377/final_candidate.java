import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class BinomialCoeff {

	/*@ public normal_behavior
	  @ requires seed >= 0 && p >= 0 && p <= seed;
	  @ ensures \result >= 0;
 
 
	  @*/
	public static int binomialCoeff(int seed, int p) {
		if (p > seed - p)
			p = seed - p;
		int b = 1;
		/*@ maintaining 1 <= r && r <= p + 1;
		  @ maintaining b >= 1;
		  @ decreasing p - r + 1;
		  @*/
		for (int r = 1; r <= p; r++) {
			b = b * (seed - r + 1) / r;
		}
		return b;
	}
}
