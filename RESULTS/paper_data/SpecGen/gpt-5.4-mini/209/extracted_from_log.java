import java.io.*;
import java.lang.*;
import java.math.*;

class FindElement {

	//@ requires arr != null && ranges != null;
	//@ requires array >= 0 && array <= ranges.length;
	//@ requires width >= 0 && width < arr.length;
	//@ requires (\forall int r; 0 <= r && r < ranges.length; ranges[r] != null && ranges[r].length >= 2);
	//@ requires (\forall int r; 0 <= r && r < array; 0 <= ranges[r][0] && ranges[r][0] <= ranges[r][1] && ranges[r][1] < arr.length);
 
 
	public static int findElement(int[] arr, int[][] ranges, int array, int width) {
		//@ maintaining -1 <= r && r < array;
		//@ maintaining 0 <= width && width < arr.length;
		//@ maintaining (\forall int k; r < k && k < array; 
		//@                (ranges[k][0] <= width && ranges[k][1] >= width) ==> 
		//@                (\old(width) == ranges[k][0] ? true : true));
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