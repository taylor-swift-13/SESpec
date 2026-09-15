import java.io.*;
import java.lang.*;
import java.math.*;

/*@ spec_public @*/ class FindMinSwaps {

    /*@ spec_public @*/
    //@ requires ints != null;
    //@ requires 0 <= array && array <= ints.length;
    //@ ensures 0 <= \result && \result <= array;
    //@ ensures (\forall int i; 0 <= i && i < ints.length; ints[i] == \old(ints[i]));
    //@ ensures array <= 1 ==> \result == 0;
	public static int findMinSwaps(int[] ints, int array) {
		int find = 0;
		int min = 0;
		int offset = 1;

        //@ maintaining 0 <= min && min <= array;
        //@ maintaining 0 <= offset && offset <= array;
        //@ maintaining 0 <= find && find <= min && find <= offset;
        //@ decreases 2*array - (min + offset);
		while (min < array && offset < array) {
			if (ints[min] == ints[offset]) {
				min++;
				offset++;
				find++;
			} else if (ints[min] > ints[offset]) {
				min++;
			} else {
				offset++;
			}
		}

		return find;
	}
}