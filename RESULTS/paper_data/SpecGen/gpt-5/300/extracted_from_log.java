import java.io.*;
import java.lang.*;
import java.math.*;

class FindPeak {

	//@ requires array != null;
	//@ requires 1 <= Array && Array <= array.length;
	//@ ensures 0 <= \result && \result < Array;
	//@ ensures (\result == 0 || array[\result] >= array[\result - 1]) && (\result == Array - 1 || array[\result] >= array[\result + 1]);
	/*@ spec_public @*/ public static int findPeak(int[] array, int Array) {
		int found = 0, top = Array - 1;
		//@ maintaining 0 <= found && found <= top && top < Array && 1 <= Array && Array <= array.length;
		//@ maintaining (found < top) ==> (found + (top - found) / 2 < top);
		//@ decreases top - found;
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