import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindEvenPair {

	//@ ensures arr == null ==> \result == -1;
	//@ ensures arr != null && arr.length == 1 ==> \result == 0;
	//@ ensures arr != null ==> 0 <= \result && \result <= (arr.length * (arr.length - 1)) / 2;
	//@ ensures arr != null ==> 
	//@   \result == (\sum int i; 0 <= i && i < arr.length;
	//@                 (\num_of int j; i + 1 <= j && j < arr.length;
	//@                     (((arr[i] ^ arr[j]) & 1) == 0)));
	public static int findEvenPair(int[] arr, int n) {
		if (arr == null) {
			return -1;
		}
		if (arr.length == 1) {
			return 0;
		}

		int evenPairCount = 0;
		//@ maintaining arr != null && 0 <= i && i <= arr.length;
		//@ maintaining 0 <= evenPairCount && evenPairCount <= (arr.length * (arr.length - 1)) / 2;
		//@ maintaining evenPairCount == (\sum int p; 0 <= p && p < i;
		//@                                  (\num_of int q; p + 1 <= q && q < arr.length;
		//@                                      (((arr[p] ^ arr[q]) & 1) == 0)));
		//@ decreases arr.length - i;
		for (int i = 0; i < arr.length; i++) {
			//@ maintaining i + 1 <= c && c <= arr.length;
			//@ maintaining 0 <= evenPairCount && evenPairCount <= (arr.length * (arr.length - 1)) / 2;
			//@ maintaining evenPairCount == 
			//@    (\sum int p; 0 <= p && p < i;
			//@        (\num_of int q; p + 1 <= q && q < arr.length;
			//@            (((arr[p] ^ arr[q]) & 1) == 0)))
			//@    + (\num_of int q; i + 1 <= q && q < c;
			//@            (((arr[i] ^ arr[q]) & 1) == 0));
			//@ decreases arr.length - c;
			for (int c = i + 1; c < arr.length; c++) {
				int odd = arr[i];
				int b = arr[c];
				int even = odd ^ b;
				if ((even & 1) == 0) {
					evenPairCount++;
				}
			}
		}
		return evenPairCount;
	}
}