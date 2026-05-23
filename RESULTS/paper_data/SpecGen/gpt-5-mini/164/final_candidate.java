import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindEvenPair {

	/*@
	  public normal_behavior
	  ensures arr == null ==> \result == -1;
	  ensures arr != null ==>
	    \result == (\sum int p; 0 <= p && p < arr.length;
	                   (\sum int q; p < q && q < arr.length;
	                      (((arr[p] ^ arr[q]) & 1) == 0 ? 1 : 0)));
	  ensures \result >= -1;
	  ensures arr != null ==> (\result >= 0 && \result <= arr.length*(arr.length-1)/2);
	@*/
	public static int findEvenPair(int[] arr, int n) {
		if (arr == null) {
			return -1;
		}
		if (arr.length == 1) {
			return 0;
		}

		int evenPairCount = 0;
		/*@ 
		  maintaining 0 <= evenPairCount && evenPairCount <= arr.length*(arr.length-1)/2;
		@*/
		/*@ 
		  maintaining 0 <= i && i <= arr.length;
		  decreases arr.length - i;
		@*/
		for (int i = 0; i < arr.length; i++) {
			/*@ 
			  maintaining i+1 <= c && c <= arr.length;
			  maintaining 0 <= evenPairCount && evenPairCount <= arr.length*(arr.length-1)/2;
			  decreases arr.length - c;
			@*/
			for (int c = i + 1; c < arr.length; c++) {
				int even = arr[i];
				int odd = arr[c];
				int z = even ^ odd;
				if ((z & 1) == 0) {
					evenPairCount++;
				}
			}
		}
		return evenPairCount;
	}
}