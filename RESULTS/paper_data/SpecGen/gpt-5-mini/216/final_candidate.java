import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class Last {

	/*@ 
	  @ requires array != null;
	  @ requires 0 <= y && y <= array.length;
	  @ // array[0..y-1] is sorted in non-decreasing order
	  @ requires (\forall int p, q; 0 <= p && p <= q && q < y; array[p] <= array[q]);
	  @ 
 
 
	  @                             && (\forall int j; \result < j && j < y; array[j] != x));
	  @*/
	public static int last(int[] array, int x, int y) {
		int i = 0;
		int r = y - 1;
		int k = -1;

		//@ maintaining 0 <= i && i <= y;
		//@ maintaining -1 <= r && r < y;
		//@ maintaining -1 <= k && k < y;
		//@ // all elements strictly before i are <= x (by sortedness and progress)
		//@ maintaining (\forall int j; 0 <= j && j < i; array[j] <= x);
		//@ // all elements strictly after r are > x
		//@ maintaining (\forall int j; r < j && j < y; array[j] > x);
		//@ // if a match has been found, k is such an index and it is before i
		//@ maintaining (k == -1) || (0 <= k && k < i && array[k] == x);
		//@ decreases r - i + 1;
		while (i <= r) {
			int tmp = (i + r) / 2;
			if (array[tmp] == x) {
				k = tmp;
				i = tmp + 1;
			} else if (array[tmp] < x) {
				i = tmp + 1;
			} else {
				r = tmp - 1;
			}
		}

		return k;
	}
}
