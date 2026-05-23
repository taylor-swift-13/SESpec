import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class BinomialCoeff {

	/*@ 
	  @ requires seed >= 0 && p >= 0 && p <= seed;
	  @ ensures \result >= 0;
	  @ ensures (\old(p) == 0) ==> (\result == 1);
	  @ ensures \result * (\product int i; 1 <= i && i <= \old(p); i) 
	  @           == (\product int i; 1 <= i && i <= \old(p); seed - i + 1);
	  @*/
	public static /*@ spec_public @*/ int binomialCoeff(int seed, int p) {
		if (p > seed - p)
			p = seed - p;
		int b = 1;
		/*@ 
 
 
 
		  @           == (\product int i; 1 <= i && i <= r-1; seed - i + 1);
		  @ decreases p - r + 1;
		  @*/
		for (int r = 1; r <= p; r++) {
			b = b * (seed - r + 1) / r;
		}
		return b;
	}
}
