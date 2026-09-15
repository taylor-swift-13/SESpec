import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class AverageOdd {

	//@ requires size >= 1 && size <= 92680;
	//@ ensures \result == (size + 1) / 2;
	public static int averageOdd(int size) {
		int average = 0;
		int total = 0;
		//@ maintaining 1 <= index && index <= size + 1;
		//@ maintaining total == (\sum int t; 1 <= t && t < index && t % 2 != 0; 1);
		//@ maintaining average == (\sum int t; 1 <= t && t < index && t % 2 != 0; t);
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