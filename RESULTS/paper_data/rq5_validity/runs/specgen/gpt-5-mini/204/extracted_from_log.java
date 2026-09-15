import java.io.*;
import java.lang.*;
import java.math.*;

class FindMinSwaps {

	/*@ spec_public @*/
	/*@ public normal_behavior
	  @   requires ints != null;
	  @   requires 0 <= array && array <= ints.length;
	  @   ensures 0 <= \result && \result <= array;
	  @   ensures (\forall int i; 0 <= i && i < ints.length; ints[i] == \old(ints[i]));
	  @*/
	public static int findMinSwaps(int[] ints, int array) {
		int find = 0;
		int offset = 0;
		int max = 1;

		/*@ 
		  @ maintaining 0 <= offset && offset <= array;
		  @ maintaining 0 <= max && max <= array;
		  @ maintaining 0 <= find && find <= array;
		  @ maintaining find <= offset && find <= max;
		  @ decreases (array - offset) + (array - max);
		  @*/
		while (offset < array && max < array) {
			if (ints[offset] == ints[max]) {
				offset++;
				max++;
				find++;
			} else if (ints[offset] > ints[max]) {
				offset++;
			} else {
				max++;
			}
		}

		return find;
	}
}