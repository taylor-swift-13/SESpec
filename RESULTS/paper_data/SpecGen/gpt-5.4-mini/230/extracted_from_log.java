import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class CountPairs {

	/*@ requires pairs != null;
	  @ requires 0 <= array;
	  @ ensures \result >= 0;
 
	  @*/
	public static int countPairs(int[] pairs, int array) {
		int count = 0;
		int total = pairs.length;
		/*@ maintaining 0 <= index && index - 1 <= total - 1;  
		  @ maintaining 0 <= count;
 
		  @ decreases total - index;
		  @*/
		for (int index = 0; index < total - 1; index++) {
			/*@ maintaining index + 1 <= k && k <= total;
			  @ maintaining 0 <= count;
 
			  @ decreases total - k;
			  @*/
			for (int k = index + 1; k < total; k++) {
				if (pairs[index] != pairs[k]) {
					count++;
				}
			}
		}
		return count;
	}
}