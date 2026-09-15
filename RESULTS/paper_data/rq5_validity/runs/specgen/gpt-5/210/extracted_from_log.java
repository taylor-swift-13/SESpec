import java.io.*;
import java.lang.*;
import java.math.*;

class FindElement {

	//@ requires arr != null && ranges != null;
	//@ requires 0 <= array && array <= ranges.length;
	//@ requires 0 <= count && count < arr.length;
	//@ requires (\forall int t; 0 <= t && t < array;
	//@              ranges[t] != null && ranges[t].length >= 2
	//@              && 0 <= ranges[t][0] && ranges[t][0] <= ranges[t][1]
	//@              && ranges[t][1] < arr.length);
	//@ assignable \nothing;
	//@ ensures 0 <= count && count < arr.length;
	//@ ensures \result == arr[count];
	public static int findElement(int[] arr, int[][] ranges, int array, int count) {
		//@ maintaining -1 <= r && r < array;
		//@ maintaining arr != null && ranges != null && 0 <= array && array <= ranges.length;
		//@ maintaining 0 <= count && count < arr.length;
		//@ maintaining (\forall int t; 0 <= t && t < array;
		//@                ranges[t] != null && ranges[t].length >= 2
		//@                && 0 <= ranges[t][0] && ranges[t][0] <= ranges[t][1]
		//@                && ranges[t][1] < arr.length);
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