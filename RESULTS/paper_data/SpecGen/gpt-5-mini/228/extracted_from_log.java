import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class EvenBinomialCoeffSum {

	/*@ public normal_behavior
	  @   requires seed >= 0;
 
 
	  @   assignable \nothing;
	  @*/
	public static int evenBinomialCoeffSum(int seed) {
		int result = 0;
		int[] temp = new int[seed + 1];
		temp[0] = 1;
		/*@ 
		  @   // Invariant for the outer loop: for all indices < d the value is already computed:
		  @   maintaining 1 <= d && d <= seed + 1;
 
		  @   maintaining temp.length == seed + 1;
		  @   decreases seed - d + 1;
		  @*/
		for (int d = 1; d <= seed; d++) {
			/*@
			  @   // Invariant for the inner loop: temp[d] is the sum of temp[0..c-1]
			  @   maintaining 0 <= c && c <= d;
 
			  @   // elements before d remain the already established values
 
			  @   decreases d - c;
			  @*/
			for (int c = 0; c < d; c++) {
				temp[d] = temp[d] + temp[c];
			}
		}
		return temp[seed];
	}
}