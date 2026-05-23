import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindEvenPair {

	//@ requires arr == null || arr.length >= 0;
	//@ ensures arr == null ==> \result == -1;
	//@ ensures arr != null && arr.length == 1 ==> \result == 0;
	//@ ensures arr != null && arr.length > 1 && \result >= 0;
	//@ ensures arr != null && arr.length > 1 ==> \result == (\num_of int i, c; 0 <= i && i < arr.length && i + 1 <= c && c < arr.length && (((arr[i] ^ arr[c]) & 1) == 0));
	public static int findEvenPair(int[] arr, int n) {
		if (arr == null) {
			return -1;
		}
		if (arr.length == 1) {
			return 0;
		}

		int evenPairCount = 0;
		//@ maintaining 0 <= evenPairCount;
		//@ maintaining 0 <= i && i <= arr.length;
 
		//@ decreases arr.length - i;
		for (int i = 0; i < arr.length; i++) {
			//@ maintaining i + 1 <= c && c <= arr.length;
			//@ maintaining evenPairCount == (\num_of int x, y; 0 < x && x <= i && x - 1 <= y && y < arr.length && (((arr[x] ^ arr[y]) & 1) == 0)) +  
			//@                                (\num_of int y; i + 1 <= y && y < c && (((arr[i] ^ arr[y]) & 1) == 0));
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