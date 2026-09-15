import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class EvenBinomialCoeffSum {

	/*@ 
	  @ requires seed >= 0;
 
 
 
	  @*/
	public static int evenBinomialCoeffSum(int seed) {
		int result = 0;
		int[] arr = new int[seed + 1];
		arr[0] = 1;
		/*@ 
		  @ maintaining arr.length == seed + 1;
		  @ maintaining 1 <= d && d <= seed+1;
 
 
		  @ decreases seed + 1 - d;
		  @*/
		for (int d = 1; d <= seed; d++) {
			/*@ 
			  @ maintaining 0 <= c && c <= d;
			  @ maintaining arr.length == seed + 1;
 
 
			  @ decreases d - c;
			  @*/
			for (int c = 0; c < d; c++) {
				arr[d] = arr[d] + arr[c];
			}
		}
		return arr[seed];
	}
}
