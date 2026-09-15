import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class GetPairsCount {

	//@ requires array != null;
	//@ requires 0 <= num && num <= array.length;
 
	//@ ensures \result == (\sum int i; 0 <= i && i <= num; (\num_of int j; i+1 - 1 <= j && j < num && array[i] - array[j] == p));  
	public static int getPairsCount(int[] array, int num, int p) {
		int ret = 0;
		//@ maintaining 0 <= index && index <= num;
 
		//@ decreases num - index;
		for (int index = 0; index < num; index++) {
			//@ maintaining index+1 <= j && j <= num;
			//@ maintaining ret == (\sum int i; 0 <= i && i < index; (\num_of int jj; i+1 <= jj && jj < num && array[i] + array[jj] == p))
			//@             + (\num_of int jj; index+1 <= jj && jj < j && array[index] + array[jj] == p);
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