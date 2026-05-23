import java.io.*;
import java.lang.*;
import java.math.*;

class FindPeak {

	/*@ public normal_behavior
	  @   requires array != null;
	  @   requires 0 < Array && Array <= array.length;
	  @   ensures 0 <= \result && \result < Array;
	  @*/
	public static int findPeak(int[] array, int Array) {
		int found = 0, top = Array - 1;
		/*@ maintaining 0 <= found && found <= top && top < Array;
		  @ decreases top - found;
		  @*/
		while (found < top) {
			int i = found + (top - found) / 2;
			if (array[i] < array[i + 1]) {
				found = i + 1;
			} else {
				top = i;
			}
		}
		return found;
	}
}