import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class AverageOdd {

	/*@ 
	  @ requires size >= 1;
	  @ ensures \result == (size + 1) / 2;
	  @*/
	public static int averageOdd(int size) {
		int average = 0;
		int total = 0;
		/*@ 
		  @ maintaining 1 <= index && index <= size + 1;
		  @ maintaining average == (index / 2) * (index / 2);
		  @ maintaining total == index / 2;
		  @ decreases size - index + 1;
		  @*/
		for (int index = 1; index <= size; index++) {
			if (index % 2 != 0) {
				average += index;
				total++;
			}
		}
		return average / total;
	}
}