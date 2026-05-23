import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class CountPairs {

	//@ requires pairs != null;
	//@ ensures \result >= 0;
 
	public static int countPairs(int[] pairs, int array) {
		int count = 0;
		int total = pairs.length;
		//@ maintaining 0 <= count;
		//@ maintaining 0 <= total && total == pairs.length;
		//@ maintaining 0 <= index && index - 1 <= total - 1;  
		//@ maintaining (\forall int i; 0 <= i && i < index; (\forall int j; i + 1 <= j && j < total; (pairs[i] == pairs[j]) || (pairs[i] != pairs[j])));
		//@ decreases total - index;
		for (int index = 0; index < total - 1; index++) {
			//@ maintaining 0 <= c && c <= total;
			//@ maintaining index + 1 <= c && c <= total;
			//@ maintaining count >= 0;
			//@ decreases total - c;
			for (int c = index + 1; c < total; c++) {
				if (pairs[index] != pairs[c]) {
					count++;
				}
			}
		}
		return count;
	}
}