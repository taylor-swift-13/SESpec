import java.io.*;
import java.lang.*;
import java.math.*;

class FindMinSwaps {

	/*@ 
	  requires array != null;
	  requires 0 <= Array && Array <= array.length;
	  ensures 0 <= \result && \result <= (Array == 0 ? 0 : Array - 1);
	  ensures (\forall int i; 0 <= i && i < array.length; array[i] == \old(array[i]));
	@*/
	public static int findMinSwaps(int[] array, int Array) {
		int find = 0;
		int offset = 0;
		int max = 1;

		/*@ 
		  maintaining 0 <= offset && offset <= Array;
		  maintaining 0 <= max && max <= Array;
		  maintaining 0 <= find && find <= (Array == 0 ? 0 : Array - 1);
		  maintaining find <= offset && find <= max;
		  maintaining (\forall int i; 0 <= i && i < array.length; array[i] == \old(array[i]));
		  decreases (Array - offset) + (Array - max);
		@*/
		while (offset < Array && max < Array) {
			if (array[offset] == array[max]) {
				offset++;
				max++;
				find++;
			} else if (array[offset] > array[max]) {
				offset++;
			} else {
				max++;
			}
		}

		return find;
	}
}