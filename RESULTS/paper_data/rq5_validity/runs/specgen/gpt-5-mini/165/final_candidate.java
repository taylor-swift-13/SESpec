import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindEvenPair {

	/*@ 
	  ensures (arr == null) ==> \result == -1;
	  ensures (arr != null) ==> \result == (
	    \sum int p; 0 <= p && p < arr.length;
	      (\sum int q; p+1 <= q && q < arr.length;
	        (((arr[p] ^ arr[q]) & 1) == 0 ? 1 : 0)
	      )
	  );
	  ensures (arr != null) ==> \result >= 0;
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
		  maintaining arr != null ==> 0 <= i && i <= arr.length;
		  maintaining arr != null ==>
		    evenPairCount == (
		      \sum int p; 0 <= p && p < i;
		        (\sum int q; p+1 <= q && q < arr.length;
		          (((arr[p] ^ arr[q]) & 1) == 0 ? 1 : 0)
		        )
		    );
		  decreases arr != null ? arr.length - i : 0;
		@*/
		for (int i = 0; i < arr.length; i++) {
			/*@ 
			  maintaining arr != null ==> i+1 <= c && c <= arr.length;
			  maintaining arr != null ==>
			    evenPairCount == (
			      (\sum int p; 0 <= p && p < i;
			        (\sum int q; p+1 <= q && q < arr.length;
			          (((arr[p] ^ arr[q]) & 1) == 0 ? 1 : 0)
			        )
			      )
			      +
			      (\sum int q; i+1 <= q && q < c;
			        (((arr[i] ^ arr[q]) & 1) == 0 ? 1 : 0)
			      )
			    );
			  decreases arr != null ? arr.length - c : 0;
			@*/
			for (int c = i + 1; c < arr.length; c++) {
				int pair = arr[i];
				int odd = arr[c];
				int even = pair ^ odd;
				if ((even & 1) == 0) {
					evenPairCount++;
				}
			}
		}
		return evenPairCount;
	}
}