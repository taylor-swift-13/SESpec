import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class EvenBinomialCoeffSum {

	/*@
	  requires b >= 0;
	  requires b <= 30; // bound to avoid integer overflow in the specification
	  ensures (b == 0 && \result == 1) || (b > 0 && \result == (1 << (b - 1)));
	@*/
	public static int evenBinomialCoeffSum(int b) {
		int result = 0;
		int[] arr = new int[b + 1];
		arr[0] = 1;

		/*@ 
		  maintaining arr.length == b + 1;
		  maintaining arr[0] == 1;
		  maintaining 1 <= d && d <= b + 1;
		  maintaining (\forall int i; 1 <= i && i < d; arr[i] == (1 << (i - 1)));
		  maintaining b - d + 1 >= 0;
		  decreases b - d + 1;
		@*/
		for (int d = 1; d <= b; d++) {
			/*@
			  maintaining 0 <= c && c <= d;
			  maintaining arr.length == b + 1;
			  maintaining (\forall int i; 1 <= i && i < d; arr[i] == (1 << (i - 1)));
			  maintaining arr[d] == (\sum int k; 0 <= k && k < c; arr[k]);
			  decreases d - c;
			@*/
			for (int c = 0; c < d; c++) {
				arr[d] = arr[d] + arr[c];
			}
		}
		return arr[b];
	}
}