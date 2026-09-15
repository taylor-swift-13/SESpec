import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class AverageOdd {

	//@ requires size >= 1;
	//@ ensures \result == (\sum int c; 1 <= c && c <= size && c % 2 != 0; c) / ((size + 1) / 2);
	//@ ensures 1 <= \result && \result <= size;
	public static int averageOdd(int size) {
		int ret = 0;
		int total = 0;
		//@ maintaining 1 <= c && c <= size + 1;
 
 
		//@ decreases size - c + 1;
		for (int c = 1; c <= size; c++) {
			if (c % 2 != 0) {
				ret += c;
				total++;
			}
		}
		return ret / total;
	}
}
