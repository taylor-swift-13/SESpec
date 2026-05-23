import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class BinomialCoeff {

	/*@ 
	  @ requires seed >= 0 && m >= 0 && m <= seed;
	  @ ensures \result >= 0;
	  @ // The result equals the binomial coefficient seed choose (\old(m)):
	  @ ensures (\product int i; 1 <= i && i <= seed; i) 
	  @          == \result * (\product int i; 1 <= i && i <= \old(m); i) * (\product int i; 1 <= i && i <= seed - \old(m); i);
	  @*/
	public static int binomialCoeff(int seed, int m) {
		if (m > seed - m)
			m = seed - m;
		int b = 1;
		/*@ 
		  @ // Loop invariant: after r-1 iterations, b * (r-1)! = product_{i = seed-(r-1)+1 .. seed} i
 
 
		  @            == (\product int i; seed - (r-1) + 1 <= i && i <= seed; i);
		  @ decreases m - r + 1;
		  @*/
		for (int r = 1; r <= m; r++) {
			b = b * (seed - r + 1) / r;
		}
		return b;
	}
}
