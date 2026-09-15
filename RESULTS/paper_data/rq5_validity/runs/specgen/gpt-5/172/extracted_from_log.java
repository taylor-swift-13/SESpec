import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindKth {

	//@ requires arr1 != null && arr != null;
	//@ requires Array == arr1.length && n == arr.length;
	//@ requires 0 <= p && p <= Array + n;
	//@ assignable \nothing;
	//@ ensures p == 0 ==> \result == -1;
	//@ ensures \result == -1 || \result != -1;
	public static int findKth(int[] arr1, int[] arr, int Array, int n, int p) {
		int result = 0;
		int s = 0;

		//@ maintaining 0 <= count && count <= p;
		//@ maintaining 0 <= result && result <= Array;
		//@ maintaining 0 <= s && s <= n;
		//@ maintaining result + s == count;
		//@ decreases p - count;
		for (int count = 0; count < p; count++) {
			if (result < Array
					&& (s >= n || arr1[result] <= arr[s])) {
				if (count == p - 1) {
					return arr1[result];
				}
				result++;
			} else {
				if (count == p - 1) {
					return arr[s];
				}
				s++;
			}
		}
		return -1;
	}
}