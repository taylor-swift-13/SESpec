import java.io.*;
import java.lang.*;
import java.math.*;

class FindMinSwaps {

    //@ requires ints != null;
    //@ requires 0 <= array && array <= ints.length;
    //@ assignable \nothing;
    //@ ensures 0 <= \result && \result <= array;
    //@ ensures array <= 1 ==> \result == 0;
    //@ ensures (\forall int i; 0 <= i && i < ints.length; ints[i] == \old(ints[i]));
	public static int findMinSwaps(int[] ints, int array) {
		int find = 0;
		int offset = 0;
		int max = 1;

        //@ maintaining 0 <= offset && offset <= max && max <= array;
        //@ maintaining 0 <= find && find <= offset && find <= max;
        //@ decreases (array - offset) + (array - max);
		while (offset < array && max < array) {
			if (ints[offset] == ints[max]) {
				offset++;
				max++;
				find++;
			} else if (ints[offset] > ints[max]) {
				offset++;
			} else {
				max++;
			}
		}

		return find;
	}
}