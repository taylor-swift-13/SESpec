import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class Difference {

	//@ requires diff >= 0;
	//@ ensures \result == (\sum int c; 1 <= c && c <= diff; c*c*c) - (\sum int c; 1 <= c && c <= diff; c);
	public static int difference(int diff) {
		int result = 0;
		int max = 0;
		//@ maintaining 1 <= c && c <= diff + 1;
		//@ maintaining result == (\sum int k; 1 <= k && k < c; k*k*k);
		//@ decreases diff - c + 1;
		for (int c = 1; c <= diff; c++) {
			result += c * c * c;
		}
		//@ maintaining 1 <= c && c <= diff + 1;
		//@ maintaining max == (\sum int k; 1 <= k && k < c; k);
		//@ decreases diff - c + 1;
		for (int c = 1; c <= diff; c++) {
			max += c;
		}
		return result - max;
	}
}