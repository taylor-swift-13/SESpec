import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class CountRotation {

	//@ requires array != null;
	//@ requires 0 <= count && count <= array.length;
	//@ assignable \nothing;
	//@ ensures 0 <= \result && \result <= count;
	//@ ensures count == 0 ==> \result == 0;
	public static int countRotation(int[] array, int count) {
		if (count == 0) {
			return 0;
		}
		int r = 0, top = count - 1;
		//@ maintaining 0 <= r && r < count;
		//@ maintaining 0 <= top && top < count;
		//@ maintaining r <= top;
		//@ decreases top - r;
		while (r < top) {
			if (array[r] < array[top]) {
				return r + 1;
			}
			int i = (r + top) / 2;
			if (array[i] > array[r]) {
				r = i;
			} else {
				top = i;
			}
		}
		return r + 1;
	}
}