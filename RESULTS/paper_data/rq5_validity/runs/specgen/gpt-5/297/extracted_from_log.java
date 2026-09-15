import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindLucas {

    //@ requires seed >= 1;
    //@ ensures \result >= 1;
    //@ ensures seed == 1 ==> \result == 1;
	public static int findLucas(int seed) {
		int[] result = new int[seed + 1];
		result[0] = 2;
		result[1] = 1;
		//@ maintaining result.length == seed + 1;
		//@ maintaining 2 <= l && l <= seed + 1;
		//@ maintaining result[0] == 2 && result[1] == 1;
		//@ maintaining result[l - 1] >= 1;
		//@ maintaining l >= 3 ==> result[l - 2] >= 1;
		//@ decreases seed - l;
		for (int l = 2; l <= seed; l++) {
			result[l] = result[l - 1]
					+ result[l - 2];
		}
		return result[seed];
	}
}