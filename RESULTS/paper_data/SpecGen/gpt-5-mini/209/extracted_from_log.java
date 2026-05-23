import java.io.*;
import java.lang.*;
import java.math.*;

class FindElement {

	/*@ 
	  @ requires arr != null;
	  @ requires ranges != null;
	  @ requires 0 <= array && array <= ranges.length;
	  @ requires 0 <= width && width < arr.length;
	  @ // each range used must be a pair of valid indices into arr
	  @ requires (\forall int i; 0 <= i && i < array; ranges[i] != null && ranges[i].length >= 2 
	  @           && 0 <= ranges[i][0] && ranges[i][0] < arr.length
	  @           && 0 <= ranges[i][1] && ranges[i][1] < arr.length);
	  @ 
	  @ // The result is exactly the element of arr at the index obtained by
	  @ // iteratively transforming the initial width by scanning ranges
	  @ // from r = array-1 down to r = 0 using the same rule as in the implementation.
 
	  @            w.length == array + 1
	  @            && (\forall int t; 0 <= t && t <= array; 0 <= w[t] && w[t] < arr.length)
	  @            && w[array] == \old(width)
	  @            && (\forall int r; 0 <= r && r < array;
	  @                    ((ranges[r][0] <= w[r+1] && ranges[r][1] >= w[r+1])
	  @                        ? (w[r] == (w[r+1] == ranges[r][0] ? ranges[r][1] : w[r+1] - 1))
	  @                        : (w[r] == w[r+1])))
	  @            && \result == arr[w[0]]
	  @          );
	  @*/
	public static int findElement(int[] arr, int[][] ranges, int array, int width) {
		/*@ 
		  @ // r ranges from array-1 down to 0
		  @ maintaining -1 <= r && r < array;
		  @ maintaining 0 <= width && width < arr.length;
		  @ decreases r + 1;
		  @*/
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