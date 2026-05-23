import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class GetPairsCount {

	//@ requires array != null;
	//@ requires 0 <= num && num <= array.length;
	//@ ensures \result >= 0;
 
	public static int getPairsCount(int[] array, int num, int p) {
		int ret = 0;
		//@ maintaining 0 <= index && index <= num;
		//@ maintaining ret >= 0;
 
		//@ decreases num - index;
		for (int index = 0; index < num; index++) {
 
 
 
			//@                  + (\num_of int k; index <= k && k < j; array[index] + array[k] == p);
			//@ decreases num - j;
			for (int j = index + 1; j < num; j++) {
				if (array[index] + array[j] == p) {
					ret++;
				}
			}
		}
		return ret;
	}
}