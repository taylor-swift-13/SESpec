import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindEvenPair {

	//@ public normal_behavior
	//@ ensures arr == null ==> \result == -1;
	//@ ensures arr != null && arr.length == 1 ==> \result == 0;
	//@ ensures arr != null && arr.length >= 2 ==>
	//@   \result == (\sum int p,q; 0 <= p && p < q && q < arr.length;
	//@                    ((((arr[p] ^ arr[q]) & 1) == 0) ? 1 : 0));
	//@ ensures \result >= -1;
	public static int findEvenPair(int[] arr, int n) {
		if (arr == null) {
			return -1;
		}
		if (arr.length == 1) {
			return 0;
		}

		int evenPairCount = 0;
 
 
 
		//@                                    ((((arr[p] ^ arr[q]) & 1) == 0) ? 1 : 0));
		//@ decreases arr.length - i;
		for (int i = 0; i < arr.length; i++) {
			//@ maintaining arr != null;
			//@ maintaining i+1 <= c && c <= arr.length;
			//@ maintaining evenPairCount == (\sum int p,q; 0 <= p && p < i && p < q && q < arr.length;
			//@                                      ((((arr[p] ^ arr[q]) & 1) == 0) ? 1 : 0))
			//@                        + (\sum int q; i+1 <= q && q < c;
			//@                                      ((((arr[i] ^ arr[q]) & 1) == 0) ? 1 : 0));
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