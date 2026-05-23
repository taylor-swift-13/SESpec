import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FrequencyOfSmallest {

	/*@ public normal_behavior
	  @   requires a != null;
	  @   requires 0 <= size && size <= a.length;
	  @   ensures size == 0 ==> \result == 0;
 
	  @     (\exists int mi; 0 <= mi && mi < size &&
	  @         (\forall int j; 0 <= j && j < size ==> a[mi] <= a[j]) &&
	  @         \result == (\sum int k; 0 <= k && k < size; (a[k] == a[mi] ? 1 : 0))
	  @     );
	  @*/
	public static int frequencyOfSmallest(int size, int[] a) {
		if (size == 0) {
			return 0;
		}

		int f = a[0];
		int total = 1;

		/*@ maintaining 1 <= c && c <= size;
		  @ maintaining (\forall int i; 0 <= i && i < c ==> a[i] >= f);
 
		  @ decreases size - c;
		  @*/
		for (int c = 1; c < size; c++) {
			if (f > a[c]) {
				f = a[c];
				total = 1;
			} else if (f == a[c]) {
				total++;
			}
		}
		return total;
	}
}