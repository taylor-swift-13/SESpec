import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindEvenPair {

	//@ requires arr == null || arr.length >= 0;
	//@ ensures arr == null ==> \result == -1;
	//@ ensures arr != null && arr.length == 1 ==> \result == 0;
 
	public static int findEvenPair(int[] arr, int n) {
		if (arr == null) {
			return -1;
		}
		if (arr.length == 1) {
			return 0;
		}

		int evenPairCount = 0;
		//@ maintaining 0 <= i && i <= arr.length;
 
		//@ decreases arr.length - i;
		for (int i = 0; i < arr.length; i++) {
			//@ maintaining i + 1 <= c && c <= arr.length;
			//@ decreases arr.length - c;
			for (int c = i + 1; c < arr.length; c++) {
				int even = arr[i];
				int odd = arr[c];
				int z = even ^ odd;
				if ((z & 1) == 0) {
					evenPairCount++;
				}
			}
		}
		//@ ensures \result == evenPairCount;
		return evenPairCount;
	}
}