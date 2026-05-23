import java.io.*;
import java.lang.*;
import java.math.*;

class FindPeak {

    //@ requires data != null;
    //@ requires 1 <= array && array <= data.length;
    //@ ensures 0 <= \result && \result < array;
    //@ ensures (\result == 0 || data[\result - 1] <= data[\result]) && (\result == array - 1 || data[\result] >= data[\result + 1]);
	public static int findPeak(int[] data, int array) {
		int found = 0, top = array - 1;
        //@ maintaining 0 <= found && found <= top && top < array;
        //@ maintaining (found == 0 || data[found - 1] <= data[found]);
        //@ maintaining (top == array - 1 || data[top] >= data[top + 1]);
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