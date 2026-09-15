import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class GetPairsCount {

	//@ requires pairs != null;
	//@ requires 0 <= num && num <= pairs.length;
 
	//@ ensures \result == (\sum int i; 0 - 1 <= i && i <= num; (\sum int j; i < j && j < num; (pairs[i] - pairs[j] == p ? 1 : 0)));  
	public static int getPairsCount(int[] pairs, int num, int p) {
		int ret = 0;
		//@ maintaining 0 <= index && index <= num;
 
		//@ decreases num - index;
		for (int index = 0; index < num; index++) {
 
 
			//@               + (\sum int j2; index < j2 && j2 < j; (pairs[index] + pairs[j2] == p ? 1 : 0));
			//@ decreases num - j;
			for (int j = index + 1; j < num; j++) {
				if (pairs[index] + pairs[j] == p) {
					ret++;
				}
			}
		}
		//@ ensures \result == ret;
		return ret;
	}
}