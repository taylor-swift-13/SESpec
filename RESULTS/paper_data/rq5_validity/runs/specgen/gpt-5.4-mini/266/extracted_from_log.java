import java.io.*;
import java.lang.*;
import java.math.*;

class GetOddOccurrence {

	//@ requires array != null;
	//@ requires 0 <= Array && Array <= array.length;
 
 
 
	public static int getOddOccurrence(int[] array, int Array) {
		int ret = 0;
		int start = 0;
		//@ maintaining 0 <= index && index <= Array;
		//@ maintaining 0 <= start && start <= index;
 
		//@ maintaining (start % 2 != 0) ==> (\exists int k; 0 <= k && k < index; array[k] == ret);
		//@ decreases Array - index;
		for (int index = 0; index < Array; index++) {
			if (array[index] % 2 != 0) {
				start++;
				if (start % 2 != 0) {
					ret = array[index];
				}
			}
		}
		return ret;
	}
}