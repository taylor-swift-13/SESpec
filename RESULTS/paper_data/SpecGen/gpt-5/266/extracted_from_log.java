import java.io.*;
import java.lang.*;
import java.math.*;

class GetOddOccurrence {

	//@ requires array != null;
	//@ requires 0 <= Array && Array <= array.length;
	//@ assignable \nothing;
	//@ ensures (\result == 0) <==> (\forall int i; 0 <= i && i < Array; array[i] % 2 == 0);
	//@ ensures \result != 0 ==> (\exists int j; 0 <= j && j < Array && array[j] % 2 != 0
	//@                         && ((\num_of int t; 0 <= t && t <= j; array[t] % 2 != 0) % 2) == 1
	//@                         && (\forall int k; j < k && k < Array;
	//@                                (array[k] % 2 != 0) ==> ((\num_of int t; 0 <= t && t <= k; array[t] % 2 != 0) % 2) == 0)
	//@                         && \result == array[j]);
	public static int getOddOccurrence(int[] array, int Array) {
		int ret = 0;
		int start = 0;
		//@ maintaining 0 <= index && index <= Array;
		//@ maintaining (ret == 0) <==> (\forall int i; 0 <= i && i < index; array[i] % 2 == 0);
		//@ maintaining ret != 0 ==> (\exists int j; 0 <= j && j < index && array[j] % 2 != 0
		//@                          && ((\num_of int t; 0 <= t && t <= j; array[t] % 2 != 0) % 2) == 1
		//@                          && (\forall int k; j < k && k < index;
		//@                                 (array[k] % 2 != 0) ==> ((\num_of int t; 0 <= t && t <= k; array[t] % 2 != 0) % 2) == 0)
		//@                          && ret == array[j]);
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