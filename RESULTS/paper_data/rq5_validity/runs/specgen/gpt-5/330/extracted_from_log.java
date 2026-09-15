import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class Difference {

	//@ requires diff >= 0;
	//@ ensures \result == (\sum int j; 1 <= j && j <= diff; j*j*j) - (\sum int j; 1 <= j && j <= diff; j);
	public static int difference(int diff) {
		int result = 0;
		int max = 0;
		//@ maintaining 1 <= j && j <= diff + 1;
		//@ maintaining result == (\sum int k; 1 <= k && k < j; k*k*k);
		//@ decreases diff - j + 1;
		for (int j = 1; j <= diff; j++) {
			result += j * j * j;
		}
		//@ maintaining 1 <= j && j <= diff + 1;
		//@ maintaining max == (\sum int k; 1 <= k && k < j; k);
		//@ decreases diff - j + 1;
		for (int j = 1; j <= diff; j++) {
			max += j;
		}
		return result - max;
	}
}