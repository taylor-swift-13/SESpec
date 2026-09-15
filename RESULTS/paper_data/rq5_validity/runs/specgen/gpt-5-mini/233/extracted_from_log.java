import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class BigDiff {

	//@ requires arr != null && arr.length > 0;
 
	//@ ensures (\exists int imax, imin; 0 < imax && imax < arr.length && 0 < imin && imin < arr.length ||  
	//@            (\forall int j; 0 <= j && j < arr.length; arr[imax] >= arr[j] && arr[imin] <= arr[j]) &&
	//@            \result == arr[imax] - arr[imin]);
	public static int bigDiff(int[] arr) {
		int result = arr[0];
		int num = arr[0];
		//@ maintaining 1 <= n && n <= arr.length;
		//@ maintaining (\forall int i; 0 <= i && i < n; result >= arr[i] && num <= arr[i]);
		//@ decreases arr.length - n;
		for (int n = 1; n < arr.length; n++) {
			if (arr[n] > result) {
				result = arr[n];
			}
			if (arr[n] < num) {
				num = arr[n];
			}
		}
		return result - num;
	}
}