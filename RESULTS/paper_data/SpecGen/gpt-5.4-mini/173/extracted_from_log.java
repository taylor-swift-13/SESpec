import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindKth {

	//@ requires arr1 != null && arr != null;
	//@ requires 0 <= Array && 0 <= n && 0 <= p;
	//@ requires Array <= arr1.length && n <= arr.length;
	//@ ensures (\result == -1) || (\exists int c; 0 - 1 <= c && c <= Array; \result == arr1[c]) && (\exists int d; 0 - 1 <= d && d < n; \result == arr[d]);  
	//@ ensures p == 0 ==> \result == -1;
	public static int findKth(int[] arr1, int[] arr, int Array, int n, int p) {
		int result = 0;
		int tmp = 0;

		//@ maintaining 0 <= count && count <= p;
		//@ maintaining 0 <= result && result <= Array;
 
		//@ maintaining (\forall int i; 0 <= i && i < result && i < Array; arr1[i] <= arr1[result == Array ? Array - 1 : result]);
		//@ maintaining (\forall int j; 0 <= j && j < tmp && j < n; arr[j] <= arr[tmp == n ? n - 1 : tmp]);
		//@ decreases p - count;
		for (int count = 0; count < p; count++) {
			if (result < Array
					&& (tmp >= n || arr1[result] <= arr[tmp])) {
				if (count == p - 1) {
					return arr1[result];
				}
				result++;
			} else {
				if (count == p - 1) {
					//@ assume 0 <= tmp && tmp < arr.length;
					return arr[tmp];
				}
				tmp++;
			}
		}
		return -1;
	}
}