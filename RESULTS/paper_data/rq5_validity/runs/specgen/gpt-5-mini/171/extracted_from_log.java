import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindKth {
	/*@ 
	  requires arr1 != null && arr != null;
	  requires Array == arr1.length && n == arr.length;
	  requires (\forall int i; 0 <= i && i+1 < Array; arr1[i] <= arr1[i+1]);
	  requires (\forall int i; 0 <= i && i+1 < n; arr[i] <= arr[i+1]);
	  requires 1 <= c && c <= Array + n;
	  ensures (\exists int i; 0 <= i && i < Array; \result == arr1[i]) || (\exists int j; 0 <= j && j < n; \result == arr[j]);
	  ensures \result != -1;
	@*/
	public static int findKth(int[] arr1, int[] arr, int Array, int n, int c) {
		int result = 0;
		int tmp = 0;

		/*@ 
		  maintaining 0 <= count && count <= c;
		  maintaining 0 <= result && result <= Array;
		  maintaining 0 <= tmp && tmp <= n;
		  maintaining count == result + tmp;
		  /* The elements already taken from arr1 (indices 0..result-1) are
		     less than or equal to the remaining elements of arr (indices tmp..n-1). */
		  maintaining (\forall int i; 0 <= i && i < result; (\forall int j; tmp <= j && j < n; arr1[i] <= arr[j]));
		  /* The elements already taken from arr (indices 0..tmp-1) are
		     less than or equal to the remaining elements of arr1 (indices result..Array-1). */
		  maintaining (\forall int i; 0 <= i && i < tmp; (\forall int j; result <= j && j < Array; arr[i] <= arr1[j]));
		  decreases c - count;
		@*/
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