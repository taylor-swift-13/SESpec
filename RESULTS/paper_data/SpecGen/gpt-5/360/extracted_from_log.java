import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class AverageOdd {

    //@ requires size >= 1;
    //@ ensures \result == (size + 1) / 2;
	public static int averageOdd(int size) {
		int average = 0;
		int total = 0;
        //@ maintaining 1 <= c && c <= size + 1;
        //@ maintaining total == c / 2;
        //@ maintaining average == total * total;
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