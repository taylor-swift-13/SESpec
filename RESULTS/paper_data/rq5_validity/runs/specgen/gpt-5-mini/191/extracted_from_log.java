import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class CountWays {

    /*@ public normal_behavior
      @   requires count >= 1;
      @   ensures \result >= 0;
      @*/
	public static int countWays(int count) {
		int[] W = new int[count + 1];
		int[] C = new int[count + 1];
		W[0] = 1;
		W[1] = 0;
		C[0] = 0;
		C[1] = 1;
		/*@ 
		  @   // Simple loop invariants to aid verification without heavy quantifiers
		  @   maintaining W.length == count + 1 && C.length == count + 1;
		  @   maintaining 2 <= w && w <= count + 1;
		  @   // values written so far are non-negative (light-weight property)
		  @   maintaining (\forall int i; 0 <= i && i < w; W[i] >= 0 && C[i] >= 0);
		  @   decreases count - w + 1;
		  @*/
		for (int w = 2; w <= count; w++) {
			W[w] = W[w - 2]
					+ 2 * C[w - 1];
			C[w] = W[w - 1] + C[w - 2];
		}
		return W[count];
	}
}