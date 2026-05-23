import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class AverageEven {

	//@ requires size >= 2;
	//@ ensures \result == (size % 2 == 0 ? size / 2 : (size - 1) / 2);
	public static int averageEven(int size) {
		int result = 0;
		int total = 0;
		//@ maintaining 1 <= c && c <= size + 1;
 
 
		//@ decreases size - c + 1;
		for (int c = 1; c <= size; c++) {
			if (c % 2 == 0) {
				result += c;
				total++;
			}
		}
		return result / total;
	}
}
