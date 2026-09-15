import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class AverageEven {

	/*@
	  requires size >= 2;
	  ensures (\sum int j; 1 <= j && j <= size && j % 2 == 0; 1) > 0;
	  ensures \result == (\sum int j; 1 <= j && j <= size && j % 2 == 0; j) /
	                    (\sum int j; 1 <= j && j <= size && j % 2 == 0; 1);
	@*/
	public static int averageEven(int size) {
		int average = 0;
		int total = 0;
		/*@
		  loop_invariant 1 <= j && j <= size + 1;
		  loop_invariant average == (\sum int t; 1 <= t && t < j && t % 2 == 0; t);
		  loop_invariant total == (\sum int t; 1 <= t && t < j && t % 2 == 0; 1);
		  decreases size - j + 1;
		@*/
		for (int j = 1; j <= size; j++) {
			if (j % 2 == 0) {
				average += j;
				total++;
			}
		}
		//@ assert total > 0;
		return average / total;
	}
}