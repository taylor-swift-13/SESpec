import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FrequencyOfSmallest {

	//@ requires 0 <= size && size <= array.length;
	//@ ensures size == 0 ==> \result == 0;
	//@ ensures size > 0 ==> (\result >= 1 && \result <= size);
 
	public static int frequencyOfSmallest(int size, int[] array) {
		if (size == 0) {
			return 0;
		}

		int f = array[0];
		int max = 1;

		//@ maintaining 1 <= c && c <= size;
		//@ maintaining max >= 1 && max <= c;
		//@ maintaining (\forall int i; 0 <= i && i < c; f <= array[i]);
 
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