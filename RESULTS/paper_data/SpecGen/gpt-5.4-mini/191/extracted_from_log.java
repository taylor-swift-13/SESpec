import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class CountWays {

	//@ requires count >= 1;
 
	public static int countWays(int count) {
		int[] W = new int[count + 1];
		int[] C = new int[count + 1];
		W[0] = 1;
		W[1] = 0;
		C[0] = 0;
		C[1] = 1;
		//@ maintaining 2 <= w && w - 1 <= count;  
		//@ maintaining W.length == count + 1 && C.length == count + 1;
		//@ maintaining W[0] == 1 && W[1] == 0 && C[0] == 0 && C[1] == 1;
		//@ decreases count - w;
		for (int w = 2; w <= count; w++) {
			W[w] = W[w - 2]
					+ 2 * C[w - 1];
			C[w] = W[w - 1] + C[w - 2];
		}
		return W[count];
	}
}