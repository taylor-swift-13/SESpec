import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class AverageEven {

	/*@ requires size >= 0;
	  @ ensures (\result == 0 && size < 2) || (\result >= 0);
	  @ ensures \result == (size <= 1 ? 0 : (
	  @     (size % 2 == 0)
	  @         ? (size / 2) + 1
	  @         : (size + 1) / 2
	  @ ));
	  @*/
	public static int averageEven(int size) {
		int average = 0;
		int total = 0;
		/*@ maintaining 1 <= j && j <= size + 1;
		  @ maintaining total >= 0;
		  @ maintaining average >= 0;
		  @ maintaining (\forall int k; 1 <= k && k < j; k % 2 != 0 ==> true);
 
 
		  @ decreases size - j + 1;
		  @*/
		for (int j = 1; j <= size; j++) {
			if (j % 2 == 0) {
				average += j;
				total++;
			}
		}
		return average / total;
	}
}
