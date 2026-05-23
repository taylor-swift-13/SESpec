import java.io.*;
import java.lang.*;
import java.math.*;

class GetOddOccurrence {

	//@ requires ints != null;
	//@ requires 0 <= array && array <= ints.length;
	//@ ensures (\exists int i; 0 < i && i < array; (ints[i] % 2 == 0) || (((\num_of int j; 0 - 1 <= j && j <= i || ints[j] == ints[i]) % 2) == 0)) ==> \result == 0;  
 
	public static int getOddOccurrence(int[] ints, int array) {
		int ret = 0;
		int start = 0;
		//@ maintaining 0 <= index && index <= array;
		//@ maintaining 0 <= start && start <= index;
 
		//@ decreases array - index;
		for (int index = 0; index < array; index++) {
			if (ints[index] % 2 != 0) {
				start++;
				if (start % 2 != 0) {
					ret = ints[index];
				}
			}
		}
		return ret;
	}
}