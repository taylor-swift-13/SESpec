import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindKth {

	/*@ 
	  @ requires arr1 != null && arr != null;
	  @ requires 0 <= Array && Array <= arr1.length;
	  @ requires 0 <= n && n <= arr.length;
	  @ requires 1 <= p && p <= Array + n;
	  @ 
	  @ ensures (\result == -1) ||
	  @         ((\exists int i; 0 <= i && i < Array; \result == arr1[i]) ||
	  @          (\exists int j; 0 <= j && j < n; \result == arr[j]));
	  @ 
	  @ // when preconditions hold, method does not return -1
 
	  @*/
	public static int findKth(int[] arr1, int[] arr, int Array, int n, int p) {
		int result = 0;
		int s = 0;

		/*@ 
		  @ maintaining 0 <= result && result <= Array;
		  @ maintaining 0 <= s && s <= n;
		  @ maintaining 0 <= count && count <= p;
		  @ maintaining count == result + s;
		  @ decreases p - count;
		  @*/
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