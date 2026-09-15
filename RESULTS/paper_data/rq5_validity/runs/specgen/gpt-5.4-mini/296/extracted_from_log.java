import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindLucas {

	//@ requires seed >= 1;
	//@ ensures \result + 1 >= 1;  
	//@ ensures seed == 1 ==> \result == 1;
	//@ ensures seed == 0 ==> \result == 2;
 
	public static int findLucas(int seed) {
		int[] result = new int[seed + 1];
		result[0] = 2;
		result[1] = 1;
		//@ maintaining 2 <= c && c <= seed + 1;
		//@ maintaining result[0] == 2 && result[1] == 1;
		//@ maintaining (\forall int i; 0 <= i && i < c && i < result.length; result[i] >= 0);
		//@ decreases seed - c + 1;
		for (int c = 2; c <= seed; c++) {
			result[c] = result[c - 1]
					+ result[c - 2];
		}
		return result[seed];
	}
}