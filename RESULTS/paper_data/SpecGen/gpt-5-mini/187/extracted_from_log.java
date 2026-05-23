import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FrequencyOfSmallest {

	/*@ 
	  @ requires array != null;
	  @ requires 0 <= size && size <= array.length;
	  @ 
	  @ ensures size == 0 ==> \result == 0;
 
 
	  @   (\exists int m; 0 <= m && m < size;
	  @       (\forall int j; 0 <= j && j < size; array[m] <= array[j])
	  @       && \result == (\sum int k; 0 <= k && k < size; (array[k] == array[m] ? 1 : 0))
	  @   );
	  @*/
	public static int frequencyOfSmallest(int size, int[] array) {
		if (size == 0) {
			return 0;
		}

		int f = array[0];
		int max = 1;

		/*@ 
		  @ maintaining 1 <= c && c <= size;
		  @ maintaining (\forall int i; 0 <= i && i < c; array[i] >= f);
 
		  @ decreases size - c;
		  @*/
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