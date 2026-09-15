import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindLucas {

	//@ requires seed >= 1 && seed <= 45;
	//@ ensures true;
	public static int findLucas(int seed) {
		int[] result = new int[seed + 1];
		result[0] = 2;
		result[1] = 1;
		//@ maintaining result != null && result.length == seed + 1;
		//@ maintaining result[0] == 2 && result[1] == 1;
		//@ maintaining 2 <= c && c <= seed + 1;
		//@ decreases seed - c + 1;
		for (int c = 2; c <= seed; c++) {
			result[c] = result[c - 1]
					+ result[c - 2];
		}
		return result[seed];
	}
}