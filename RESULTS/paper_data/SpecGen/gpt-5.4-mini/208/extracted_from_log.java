import java.io.*;
import java.lang.*;
import java.math.*;

class FindElement {

	//@ requires arr != null && ranges != null;
	//@ requires num >= 0;
	//@ requires 0 <= count && count < arr.length;
	//@ requires (\forall int r; 0 <= r && r < num; ranges[r] != null && ranges[r].length >= 2);
	//@ requires (\forall int r; 0 <= r && r < num; 0 <= ranges[r][0] && ranges[r][0] <= ranges[r][1]);
	//@ requires (\forall int r; 0 <= r && r < num; ranges[r][1] < arr.length);
 
	public static int findElement(int[] arr, int[][] ranges, int num, int count) {
		//@ maintaining -1 <= r && r < num;
		//@ maintaining 0 <= count && count < arr.length;
		//@ maintaining (\forall int k; r < k && k < num; ranges[k] != null && ranges[k].length >= 2);
		//@ decreases r + 1;
		for (int r = num - 1; r >= 0; r--) {
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