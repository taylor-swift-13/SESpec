import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class CountWays {

	/*@ 
	  @ requires count >= 1;
 
	  @ ensures count == 1 ==> \result == 0;
	  @*/
	public static int countWays(int count) {
		int[] w = new int[count + 1];
		int[] C = new int[count + 1];
		w[0] = 1;
		w[1] = 0;
		C[0] = 0;
		C[1] = 1;
		/*@ 
		  @ // Basic structural loop invariants (kept simple to help automated provers)
		  @ maintaining 2 <= index && index <= count + 1;
		  @ maintaining w.length == count + 1 && C.length == count + 1;
		  @ maintaining w[0] == 1 && w[1] == 0 && C[0] == 0 && C[1] == 1;
		  @ decreases count - index + 1;
		  @*/
		for (int index = 2; index <= count; index++) {
			w[index] = w[index - 2]
					+ 2 * C[index - 1];
			C[index] = w[index - 1] + C[index - 2];
		}
		return w[count];
	}
}