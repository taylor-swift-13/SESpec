import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class AverageOdd {

	/*@ spec_public @*/ public static int averageOdd(int size) {
		//@ requires size > 0;
		//@ ensures \result == (\sum int i; 1 <= i && i <= size && i % 2 != 0; i) / (\count int i; 1 <= i && i <= size && i % 2 != 0);
		int average = 0;
		int total = 0;
		//@ maintaining 1 <= index && index <= size + 1;
		//@ maintaining average == (\sum int i; 1 <= i && i < index && i % 2 != 0; i);
		//@ maintaining total == (\count int i; 1 <= i && i < index && i % 2 != 0);
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