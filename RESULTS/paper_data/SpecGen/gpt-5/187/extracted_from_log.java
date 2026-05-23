import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FrequencyOfSmallest {

	//@ requires array != null;
	//@ requires 0 <= size && size <= array.length;
	//@ ensures size == 0 ==> \result == 0;
	//@ ensures size > 0 ==> 1 <= \result && \result <= size;
	//@ ensures size > 0 ==> \result == (\num_of int i; 0 <= i && i < size && array[i] == (\min int j; 0 <= j && j < size; array[j]); true);
	/*@ spec_public @*/ public static int frequencyOfSmallest(int size, int[] array) {
		if (size == 0) {
			return 0;
		}

		int f = array[0];
		int max = 1;

		//@ maintaining 1 <= c && c <= size;
		//@ maintaining f == (\min int j; 0 <= j && j < c; array[j]);
		//@ maintaining max == (\num_of int i; 0 <= i && i < c && array[i] == f; true);
		//@ decreases size - c;
		for (int c = 1; c < size; c++) {
			if (f > array[c]) {
				f = array[c];
				max = 1;
			} else if (f == array[c]) {
				max++;
			}
		}
		return max;
	}
}