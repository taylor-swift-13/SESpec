import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class BinomialCoeff {

	//@ requires seed >= 0 && 0 <= p && p <= seed;
	//@ ensures (\old(p) == 0 || \old(p) == seed) ==> \result == 1;
	//@ ensures (\old(p) == 1 || \old(p) == seed - 1) ==> \result == seed;
	public static int binomialCoeff(int seed, int p) {
		if (p > seed - p)
			p = seed - p;
		int b = 1;
		//@ maintaining 1 <= r && r <= p + 1;
		//@ maintaining 0 <= p && p <= seed;
		//@ decreases p - r + 1;
		for (int r = 1; r <= p; r++) {
			b = b * (seed - r + 1) / r;
		}
		return b;
	}
}