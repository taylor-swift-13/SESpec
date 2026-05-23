import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FrequencyOfSmallest {

	//@ requires size >= 0 && a != null && a.length >= size;
 
	//@ ensures size > 0 ==> (\exists int m; 0 < m && m <= size && (\forall int i; 0 < i && i <= size; a[m] - 1 <= a[i]) && \result == (\num_of int i; 0 <= i && i < size; a[i] == a[m]));  
	public static int frequencyOfSmallest(int size, int[] a) {
		if (size == 0) {
			return 0;
		}

		int f = a[0];
		int max = 1;

		/*@ 
		  @ maintaining 0 <= c && c <= size;
		  @ maintaining (\forall int i; 0 <= i && i < c; a[i] >= f);
 
		  @ decreases size - c;
		  @*/
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