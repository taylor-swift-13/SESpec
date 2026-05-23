import java.io.*;
import java.lang.*;
import java.math.*;

class FindElement {

	/*@ public normal_behavior
	  @ requires arr != null && ranges != null;
	  @ requires array >= 0 && array <= ranges.length;
	  @ requires count >= 0 && count < arr.length;
	  @ requires (\forall int r; 0 <= r && r < array;
	  @              ranges[r] != null && ranges[r].length >= 2);
	  @ requires (\forall int r; 0 <= r && r < array;
	  @              0 <= ranges[r][0] && ranges[r][0] <= ranges[r][1]);
	  @ requires (\forall int r; 0 <= r && r < array;
	  @              ranges[r][1] < arr.length);
	  @ ensures 0 <= \result && \result < arr.length;
	  @ ensures (\exists int c; 0 <= c && c < arr.length;
	  @             \result == arr[c]);
	  @*/
	public static int findElement(int[] arr, int[][] ranges, int array, int count) {
		//@ maintaining 0 < r && r <= array;  
		//@ maintaining 0 <= count && count < arr.length;
		//@ maintaining (\forall int k; r < k && k < array; true);
		//@ decreases r + 1;
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