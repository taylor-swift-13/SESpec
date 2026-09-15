import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class GetPairsCount {

	//@ requires pairs != null;
	//@ requires 0 <= num && num <= pairs.length;
 
	//@ ensures 0 <= \result && \result <= num*(num-1)/2;
	public static int getPairsCount(int[] pairs, int num, int p) {
		int result = 0;
		//@ maintaining 0 <= index && index <= num;
		//@ maintaining 0 <= result && result <= num*(num-1)/2;
 
		//@ decreases num - index;
		for (int index = 0; index < num; index++) {
 
 
 
			//@            + (\sum int kk; index+1 <= kk && kk < j; (pairs[index] + pairs[kk] == p ? 1 : 0));
			//@ decreases num - j;
			for (int j = index + 1; j < num; j++) {
				if (pairs[index] + pairs[j] == p) {
					result++;
				}
			}
		}
		return result;
	}
}
