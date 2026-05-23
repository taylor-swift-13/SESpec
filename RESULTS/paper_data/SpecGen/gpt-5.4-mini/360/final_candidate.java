import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class AverageOdd {

	//@ requires size >= 1;
	//@ ensures \result == ((size % 2 == 0) ? (size * size / 4) : ((size + 1) * (size + 1) / 4)) / ((size + 1) / 2);
	public static int averageOdd(int size) {
		int average = 0;
		int total = 0;
		//@ maintaining 1 <= c && c <= size + 1;
		//@ maintaining total >= 0;
		//@ maintaining average >= 0;
 
 
		//@ decreases size - c + 1;
		for (int c = 1; c <= size; c++) {
			if (c % 2 != 0) {
				average += c;
				total++;
			}
		}
		return average / total;
	}
}
