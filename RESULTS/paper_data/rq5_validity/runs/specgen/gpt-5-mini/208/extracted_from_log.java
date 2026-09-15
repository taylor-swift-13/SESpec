import java.io.*;
import java.lang.*;
import java.math.*;

class FindElement {

	/*@ 
	  @ requires arr != null;
	  @ requires ranges != null;
	  @ requires num >= 0 && num <= ranges.length;
	  @ requires (\forall int r; 0 <= r && r < num; ranges[r] != null && ranges[r].length >= 2);
	  @ requires (\forall int r; 0 <= r && r < num; 0 <= ranges[r][0] && ranges[r][0] < arr.length && 0 <= ranges[r][1] && ranges[r][1] < arr.length);
	  @ requires 0 <= count && count < arr.length;
	  @ ensures 0 <= count && count < arr.length;
 
	  @*/
	public static int findElement(int[] arr, int[][] ranges, int num, int count) {
		/*@ 
		  @ maintaining -1 <= r && r < num;
		  @ maintaining 0 <= count && count < arr.length;
		  @ decreases r + 1;
		  @*/
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