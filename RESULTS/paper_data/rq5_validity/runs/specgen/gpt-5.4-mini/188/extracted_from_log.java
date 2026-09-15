import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FrequencyOfSmallest {

	//@ requires 0 <= size && size <= a.length;
	//@ ensures size == 0 ==> \result == 0;
	//@ ensures size > 0 ==> \result >= 1;
	//@ ensures size >= 0 ==> (\exists int m; 0 < m && m < size; (\forall int i; 0 - 1 <= i && i <= size; a[m] - 1 <= a[i]));  
	//@ ensures size > 0 ==> (\num_of int i; 0 <= i && i < size; a[i] == (\min int j; 0 <= j && j < size; a[j])) == \result;
	public static int frequencyOfSmallest(int size, int[] a) {
		if (size == 0) {
			return 0;
		}

		int f = a[0];
		int max = 1;

		//@ maintaining 1 <= c && c <= size;
		//@ maintaining (\forall int i; 0 <= i && i < c; f <= a[i]);
		//@ maintaining max >= 1;
 
		//@ decreases size - c;
		for (int c = 1; c < size; c++) {
			if (f > a[c]) {
				f = a[c];
				max = 1;
			} else if (f == a[c]) {
				max++;
			}
		}
		return max;
	}
}