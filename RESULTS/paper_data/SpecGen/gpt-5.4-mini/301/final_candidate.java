import java.io.*;
import java.lang.*;
import java.math.*;

class FindPeak {

	//@ requires data != null && 0 < array && array <= data.length;
	//@ ensures 0 <= \result && \result < array;
 
 
	public static int findPeak(int[] data, int array) {
		int found = 0, top = array - 1;
		//@ maintaining 0 <= found && found <= top && top < array;
		//@ maintaining 0 <= found && found < data.length;
		//@ maintaining 0 <= top && top < data.length;
		//@ decreases top - found;
		while (found < top) {
			int i = found + (top - found) / 2;
			if (data[i] < data[i + 1]) {
				found = i + 1;
			} else {
				top = i;
			}
		}
		return found;
	}
}
