import java.io.*;
import java.lang.*;
import java.math.*;

class FindMinSwaps {

	//@ requires array != null;
	//@ requires 0 <= Array && Array <= array.length;
	//@ ensures 0 <= \result;
	public static int findMinSwaps(int[] array, int Array) {
		int find = 0;
		int offset = 0;
		int max = 1;

		//@ maintaining 0 <= offset && offset <= Array;
		//@ maintaining 1 <= max && max - 1 <= Array;  
		//@ maintaining 0 <= find;
		//@ maintaining find <= offset;
		//@ maintaining find <= max;
		//@ decreases (Array - offset) + (Array - max);
		while (offset < Array && max < Array) {
			if (array[offset] == array[max]) {
				offset++;
				max++;
				find++;
			} else if (array[offset] > array[max]) {
				offset++;
			} else {
				max++;
			}
		}

		return find;
	}
}