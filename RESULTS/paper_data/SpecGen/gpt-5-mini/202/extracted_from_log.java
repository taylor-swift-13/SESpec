import java.io.*;
import java.lang.*;
import java.math.*;

class FindMinSwaps {

	/*@ 
	  @ requires ints != null;
	  @ requires 0 <= array && array <= ints.length;
	  @
 
 
	  @ ensures (\forall int i; 0 <= i && i < array; ints[i] == \old(ints[i]));
 
	  @*/
	public static int findMinSwaps(int[] ints, int array) {
		int find = 0;
		int min = 0;
		int offset = 1;

		/*@ 
		  @ maintaining 0 <= min && min <= array;
		  @ maintaining 0 < offset && offset - 1 <= array;  
		  @ maintaining offset >= min;
 
		  @ maintaining (\forall int i; 0 <= i && i < array; ints[i] == \old(ints[i]));
		  @ decreases (array - min) + (array - offset);
		  @*/
		while (min < array && offset < array) {
			if (ints[min] == ints[offset]) {
				min++;
				offset++;
				find++;
			} else if (ints[min] > ints[offset]) {
				min++;
			} else {
				offset++;
			}
		}

		return find;
	}
}