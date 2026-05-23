import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class CountRotation {

	/*@ 
	  @ requires array != null;
	  @ requires 0 <= count && count <= array.length;
	  @ ensures count == 0 ==> \result == 0;
	  @ ensures count > 0 ==> 1 <= \result && \result <= count;
	  @ ensures 0 <= \result && \result <= count;
	  @*/
	public static int countRotation(int[] array, int count) {
		if (count == 0) {
			return 0;
		}
		int r = 0, top = count - 1;
		/*@ 
		  @ maintaining 0 <= r && r <= top && top < count;
		  @ maintaining 0 <= top && top < count;
		  @ maintaining r >= 0;
		  @ decreases top - r;
		  @*/
		while (r < top) {
			if (array[r] < array[top]) {
				return r + 1;
			}
			int end = (r + top) / 2;
			if (array[end] > array[r]) {
				r = end;
			} else {
				top = end;
			}
		}
		return r + 1;
	}
}