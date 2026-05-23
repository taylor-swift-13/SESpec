import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindKth {

	/*@
	  @ requires arr1 != null && arr != null;
	  @ requires 0 <= Array && Array <= arr1.length;
	  @ requires 0 <= n && n <= arr.length;
	  @ // If p is outside the combined lengths, the method yields -1.
	  @ ensures (p < 1 || p > Array + n) ==> \result == -1;
	  @ // If p is within bounds, the result is some element taken from one of the two arrays
 
	  @           ((\exists int i; 0 <= i && i < Array; \result == arr1[i])
	  @         || (\exists int j; 0 <= j && j < n; \result == arr[j]));
	  @*/
	public static int findKth(int[] arr1, int[] arr, int Array, int n, int p) {
		int result = 0;
		int tmp = 0;

		/*@
		  @ maintaining 0 <= result && result <= Array;
		  @ maintaining 0 <= tmp && tmp <= n;
 
		  @ maintaining result + tmp == count;
		  @ decreases p - count;
		  @*/
		for (int count = 0; count < p; count++) {
			if (result < Array
					&& (tmp >= n || arr1[result] <= arr[tmp])) {
				if (count == p - 1) {
					return arr1[result];
				}
				result++;
			} else {
				if (count == p - 1) {
					return arr[tmp];
				}
				tmp++;
			}
		}
		return -1;
	}
}