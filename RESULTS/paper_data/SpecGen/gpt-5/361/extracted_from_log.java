import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class AverageEven {

	/*@ spec_public @*/
	//@ requires size >= 2;
	//@ ensures \result == size/2 + 1;
	public static int averageEven(int size) {
		int average = 0;
		int total = 0;
		//@ maintaining 1 <= j && j <= size + 1;
		//@ maintaining total == (j - 1) / 2;
		//@ maintaining average == ((j - 1) / 2) * (((j - 1) / 2) + 1);
		//@ decreases size - j + 1;
		for (int j = 1; j <= size; j++) {
			if (j % 2 == 0) {
				average += j;
				total++;
			}
		}
		return average / total;
	}
}