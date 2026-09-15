import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class Last {

    //@ requires array != null;
    //@ requires 0 <= y && y <= array.length;
    //@ ensures -1 <= \result && \result < y;
    //@ ensures \result == -1 || array[\result] == x;
	public static int last(int[] array, int x, int y) {
		int i = 0;
		int r = y - 1;
		int k = -1;

        //@ maintaining 0 <= i && -1 <= r && r < y && i <= y;
        //@ maintaining -1 <= k && k < y;
        //@ decreases r - i;
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