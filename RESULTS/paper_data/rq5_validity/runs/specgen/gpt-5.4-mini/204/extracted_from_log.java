import java.io.*;
import java.lang.*;
import java.math.*;

class FindMinSwaps {

	//@ requires ints != null;
	//@ requires 0 <= array && array <= ints.length;
	//@ ensures \result >= 0;
	//@ ensures \result <= array;
	public static int findMinSwaps(int[] ints, int array) {
		int find = 0;
		int offset = 0;
		int max = 1;

		//@ maintaining 0 <= offset && offset <= array;
		//@ maintaining 1 <= max && max - 1 <= array;  
		//@ maintaining 0 <= find && find <= array;
		//@ maintaining find <= offset;
		//@ maintaining find <= max;
		//@ decreases array - offset + array - max;
		while (offset < array && max < array) {
			if (ints[offset] == ints[max]) {
				offset++;
				max++;
				find++;
			} else if (ints[offset] > ints[max]) {
				offset++;
			} else {
				max++;
			}
		}

		return find;
	}
}