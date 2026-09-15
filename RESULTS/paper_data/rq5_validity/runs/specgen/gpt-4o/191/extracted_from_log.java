import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class CountWays {

	//@ requires count >= 0;
	//@ ensures \result >= 0;
	//@ ensures (\forall int w; 0 <= w && w <= count; (\forall int i; 0 <= i && i <= w; (\exists int[] W, C; W[i] >= 0 && C[i] >= 0)));
	public static int countWays(int count) {
		int[] W = new int[count + 1];
		int[] C = new int[count + 1];
		//@ assume 1 < W.length;
		W[0] = 1;
		W[1] = 0;
		//@ assume 1 < C.length;
		C[0] = 0;
		C[1] = 1;
		//@ maintaining 2 <= w && w <= count + 1;
		//@ maintaining (\forall int i; 0 <= i && i < w; W[i] >= 0 && C[i] >= 0);
		//@ decreases count - w + 1;
		for (int w = 2; w <= count; w++) {
			//@ assume w - 2 >= 0 && w - 2 < W.length;
			//@ assume w - 1 >= 0 && w - 1 < C.length;
			//@ assume w - 1 >= 0 && w - 1 < W.length;
			//@ assume w - 2 >= 0 && w - 2 < C.length;
			W[w] = W[w - 2]
					+ 2 * C[w - 1];
			C[w] = W[w - 1] + C[w - 2];
		}
		return W[count];
	}
}