import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class CountPairs {

	//@ requires pairs != null;
 
	//@ ensures 0 <= \result && \result <= pairs.length*(pairs.length-1)/2;
	public static int countPairs(int[] pairs, int array) {
		int count = 0;
		int total = pairs.length;
		//@ maintaining 0 <= index && index <= total;
 
		//@ maintaining 0 <= count && count <= total*(total-1)/2;
		//@ decreases total - index;
		for (int index = 0; index < total - 1; index++) {
			//@ maintaining index+1 <= k && k <= total;
			//@ maintaining count == (\sum int i; 0 < i && i <= index; (\sum int j; i+1 < j && j <= total; (pairs[i] != pairs[j] ? 1 : 0))) + (\sum int j; index+1 <= j && j < k; (pairs[index] != pairs[j] ? 1 : 0));  
			//@ maintaining 0 <= count && count <= total*(total-1)/2;
			//@ decreases total - k;
			for (int k = index + 1; k < total; k++) {
				if (pairs[index] != pairs[k]) {
					count++;
				}
			}
		}
		return count;
	}
}