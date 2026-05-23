import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindKth {

	//@ requires arr1 != null && arr != null;
	//@ requires 0 <= Array && Array <= arr1.length;
	//@ requires 0 <= n && n <= arr.length;
	//@ requires 0 <= c && c <= Array + n;
	//@ ensures true;
	/*@ spec_public @*/ public static int findKth(int[] arr1, int[] arr, int Array, int n, int c) {
		int result = 0;
		int tmp = 0;

		//@ maintaining 0 <= result && result <= Array;
		//@ maintaining 0 <= tmp && tmp <= n;
		//@ maintaining 0 <= count && count <= c;
		for (int count = 0; count < c; count++) {
			if (result < Array
					&& (tmp >= n || arr1[result] <= arr[tmp])) {
				if (count == c - 1) {
					return arr1[result];
				}
				result++;
			} else {
				if (count == c - 1) {
					return arr[tmp];
				}
				tmp++;
			}
		}
		return -1;
	}
}