import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class BigDiff {

	//@ requires arr != null && arr.length > 0;
 
	public static int bigDiff(int[] arr) {
		int result = arr[0];
		int num = arr[0];
		//@ maintaining 1 <= n && n <= arr.length;
		//@ maintaining (\forall int i; 0 <= i && i < n; result >= arr[i]);
		//@ maintaining (\forall int i; 0 <= i && i < n; num <= arr[i]);
		//@ decreasing arr.length - n;
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