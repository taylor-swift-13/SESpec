import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindLucas {

	//@ requires seed >= 1;
	//@ ensures \result > 0;
	//@ ensures (\exists int[] result; result.length == seed + 1; result[0] == 2 && result[1] == 1);
	//@ ensures \result == (\let int[] result = new int[seed + 1]; result[0] = 2; result[1] = 1; \forall int l; 2 <= l && l <= seed; result[l] == result[l - 1] + result[l - 2]; result[seed]);
	public static int findLucas(int seed) {
		int[] result = new int[seed + 1];
		result[0] = 2;
		result[1] = 1;
		//@ maintaining 2 <= l && l <= seed + 1;
		//@ maintaining result.length == seed + 1;
		//@ maintaining result[0] == 2 && result[1] == 1;
		//@ maintaining (\forall int i; 2 <= i && i < l; result[i] == result[i - 1] + result[i - 2]);
		//@ decreases seed - l + 1;
		for (int l = 2; l <= seed; l++) {
			result[l] = result[l - 1]
					+ result[l - 2];
		}
		return result[seed];
	}
}