import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class AverageOdd {

	//@ requires size >= 1;
	//@ ensures \result == ((size % 2 == 0) ? (size / 2) : ((size + 1) / 2));
	public static int averageOdd(int size) {
		int ret = 0;
		int total = 0;
		//@ maintaining 1 <= c && c <= size + 1;
		//@ maintaining total >= 0;
		//@ maintaining ret >= 0;
		//@ maintaining total == ((c - 1) / 2);
 
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
