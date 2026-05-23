import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

/*@ spec_public @*/
class BinomialCoeff {

    /*@ 
      @ public normal_behavior
      @   requires seed >= 0 && 0 <= m && m <= seed;
      @   assignable \nothing;
      @   ensures \result >= 1;
      @   ensures (\old(m) == 0 || \old(m) == \old(seed)) ==> \result == 1;
      @   ensures (\old(m) == 1 || \old(m) == \old(seed) - 1) ==> \result == \old(seed);
      @*/
    /*@ spec_public @*/
	public static int binomialCoeff(int seed, int m) {
		if (m > seed - m)
			m = seed - m;
		int b = 1;
        //@ maintaining 1 <= r && r <= m + 1;
        //@ maintaining seed >= 0 && m >= 0;
        //@ maintaining b >= 1;
        //@ decreases m - r + 1;
		for (int r = 1; r <= m; r++) {
			b = b * (seed - r + 1) / r;
		}
		return b;
	}
}