import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class AverageEven {

	/*@ requires size >= 0;
	  @ ensures size < 2 ==> \result == 0;
	  @ ensures size >= 2 ==> \result == (2 * (size / 2) + 2) / 2;
	  @*/
	public static int averageEven(int size) {
		int average = 0;
		int total = 0;
		/*@ maintaining 1 <= c && c <= size + 1;
 
 
		  @ decreases size - c + 1;
		  @*/
		for (int c = 1; c <= size; c++) {
			if (c % 2 == 0) {
				average += c;
				total++;
			}
		}
		return average / total;
	}
}
