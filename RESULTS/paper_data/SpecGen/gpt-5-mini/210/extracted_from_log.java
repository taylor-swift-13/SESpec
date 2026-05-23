import java.io.*;
import java.lang.*;
import java.math.*;

class FindElement {

	/*@ 
	  @ requires arr != null;
	  @ requires ranges != null;
	  @ requires 0 <= array && array <= ranges.length;
	  @ requires 0 <= count && count < arr.length;
	  @ // each specified range is a pair [j, top] inside arr bounds
	  @ requires (\forall int r; 0 <= r && r < array; 
	  @              ranges[r] != null &&
	  @              ranges[r].length >= 2 &&
	  @              0 <= ranges[r][0] &&
	  @              ranges[r][0] <= ranges[r][1] &&
	  @              ranges[r][1] < arr.length);
	  @ 
	  @ // arr is not modified by this method
	  @ ensures (\forall int i; 0 <= i && i < arr.length; arr[i] == \old(arr[i]));
	  @ 
	  @ // result is some element from arr
	  @ ensures (\exists int k; 0 <= k && k < arr.length && \result == arr[k]);
	  @ 
	  @ // if no range contains the original count then the result is the original arr[count]
	  @ ensures (\exists int r; 0 < r && r < array; !(ranges[r][0] < \old(count) || \old(count) <= ranges[r][1]))  
	  @         ==> \result == \old(arr[\old(count)]);
	  @*/
	public static int findElement(int[] arr, int[][] ranges, int array, int count) {
		/*@ 
		  @ // loop invariants:
		  @ maintaining -1 <= r && r < array;
		  @ maintaining 0 <= count && count < arr.length;
		  @ // the ranges are well-formed (kept from precondition)
		  @ maintaining (\forall int t; 0 <= t && t < array;
		  @                 ranges[t] != null &&
		  @                 ranges[t].length >= 2 &&
		  @                 0 <= ranges[t][0] &&
		  @                 ranges[t][0] <= ranges[t][1] &&
		  @                 ranges[t][1] < arr.length);
		  @ decreases r + 1;
		  @*/
		for (int r = array - 1; r >= 0; r--) {
			int j = ranges[r][0];
			int top = ranges[r][1];
			if (j <= count && top >= count) {
				if (count == j) {
					count = top;
				} else {
					count = count - 1;
				}
			}
		}
		return arr[count];
	}
}