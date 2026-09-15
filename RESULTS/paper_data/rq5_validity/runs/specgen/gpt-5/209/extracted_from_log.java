import java.io.*;
import java.lang.*;
import java.math.*;

class FindElement {

	//@ requires arr != null && ranges != null;
	//@ requires 0 <= array && array <= ranges.length;
	//@ requires 0 <= width && width < arr.length;
	//@ requires (\forall int r; 0 <= r && r < array;
	//@             ranges[r] != null && ranges[r].length >= 2
	//@             && 0 <= ranges[r][0] && ranges[r][0] <= ranges[r][1] && ranges[r][1] < arr.length);
	//@ ensures 0 <= width && width < arr.length;
	//@ ensures (\forall int i; 0 <= i && i < arr.length; arr[i] == \old(arr[i]));
	//@ ensures (\forall int rr; 0 <= rr && rr < ranges.length;
	//@            ranges[rr] != null ==> (\forall int c; 0 <= c && c < ranges[rr].length; ranges[rr][c] == \old(ranges[rr][c])));
	//@ ensures \result == arr[width];
	public static int findElement(int[] arr, int[][] ranges, int array, int width) {
		//@ maintaining -1 <= r && r < array;
		//@ maintaining 0 <= width && width < arr.length;
		//@ maintaining (\forall int i; 0 <= i && i < arr.length; arr[i] == \old(arr[i]));
		//@ maintaining (\forall int rr; 0 <= rr && rr < ranges.length;
		//@              ranges[rr] != null ==> (\forall int c; 0 <= c && c < ranges[rr].length; ranges[rr][c] == \old(ranges[rr][c])));
		//@ decreases r + 1;
		for (int r = array - 1; r >= 0; r--) {
			int j = ranges[r][0];
			int top = ranges[r][1];
			if (j <= width && top >= width) {
				if (width == j) {
					width = top;
				} else {
					width = width - 1;
				}
			}
		}
		return arr[width];
	}
}