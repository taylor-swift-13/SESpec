import java.io.*;
import java.lang.*;
import java.math.*;

class FindMinSwaps {

	//@ requires ints != null;
	//@ requires array >= 0 && array <= ints.length;
	//@ ensures 0 <= \result && \result <= array;
	public static int findMinSwaps(int[] ints, int array) {
		int find = 0;
		int min = 0;
		int offset = 1;

		//@ maintaining 0 <= find && find <= min && min <= array;
		//@ maintaining 1 <= offset && offset - 1 <= array;  
		//@ maintaining min <= offset;
		//@ decreases (array - min) + (array - offset);
		while (min < array && offset < array) {
			if (ints[min] == ints[offset]) {
				min++;
				offset++;
				find++;
			} else if (ints[min] > ints[offset]) {
				min++;
			} else {
				offset++;
			}
		}

		return find;
	}
}