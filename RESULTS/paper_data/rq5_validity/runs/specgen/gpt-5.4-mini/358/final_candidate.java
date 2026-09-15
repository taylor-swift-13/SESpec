import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class AverageOdd {

	//@ requires size >= 1;
	//@ ensures \result >= 1;
	//@ ensures \result == ( (1 + (size % 2 == 0 ? size - 1 : size)) * ((size + 1) / 2) ) / ((size + 1) / 2);
	public static int averageOdd(int size) {
		int average = 0;
		int total = 0;
		//@ maintaining 1 <= index && index <= size + 1;
 
 
		//@ decreases size - index + 1;
		for (int index = 1; index <= size; index++) {
			if (index % 2 != 0) {
				average += index;
				total++;
			}
		}
		return average / total;
	}
}
