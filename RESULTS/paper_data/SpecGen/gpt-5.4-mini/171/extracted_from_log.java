import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindKth {

	//@ requires arr1 != null && arr != null;
	//@ requires 0 <= Array && Array <= arr1.length;
	//@ requires 0 <= n && n <= arr.length;
	//@ requires 0 <= c;
	//@ ensures (\result == -1) || (\exists int i; 0 - 1 <= i && i <= Array; \result == arr1[i]) && (\exists int j; 0 < j && j <= n; \result == arr[j]);  
	//@ ensures c == 0 ==> \result == -1;
	public static int findKth(int[] arr1, int[] arr, int Array, int n, int c) {
		int result = 0;
		int tmp = 0;

		//@ maintaining 0 <= count && count <= c;
		//@ maintaining 0 <= result && result <= Array;
		//@ maintaining 0 <= tmp && tmp - 1 <= n;  
		//@ maintaining result + tmp == count;
		//@ decreasing c - count;
		for (int count = 0; count < c; count++) {
			if (result < Array
					&& (tmp >= n || arr1[result] <= arr[tmp])) {
				if (count == c - 1) {
					return arr1[result];
				}
				result++;
			} else {
				if (count == c - 1) {
					//@ assume 0 <= tmp && tmp < arr.length;
					return arr[tmp];
				}
				tmp++;
			}
		}
		return -1;
	}
}