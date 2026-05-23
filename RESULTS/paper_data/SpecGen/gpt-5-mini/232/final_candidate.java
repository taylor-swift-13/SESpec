import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class CountPairs {

	/*@ 
	  requires pairs != null;
	  // result equals number of index pairs (i,j) with 0<=i<j<pairs.length and pairs[i] != pairs[j]
	  ensures \result == (\sum int i; 0 <= i && i < pairs.length - 1;
	                       (\sum int j; i+1 <= j && j < pairs.length;
	                         (pairs[i] != pairs[j] ? 1 : 0)));
	  ensures 0 <= \result && \result <= pairs.length * (pairs.length - 1) / 2;
	  // method does not modify the contents of the input array
	  ensures (\forall int i; 0 <= i && i < pairs.length; pairs[i] == \old(pairs[i]));
	@*/
	public static int countPairs(int[] pairs, int array) {
		int count = 0;
		int total = pairs.length;
		/*@ 
		  maintaining 0 <= index && index <= total;
		  maintaining count == (\sum int ii; 0 <= ii && ii < index;
		                         (\sum int jj; ii+1 <= jj && jj < total;
		                           (pairs[ii] != pairs[jj] ? 1 : 0)));
		@*/
		for (int index = 0; index < total - 1; index++) {
			/*@
			  maintaining index+1 <= c && c <= total;
			  maintaining count == (\sum int ii; 0 <= ii && ii < index;
			                         (\sum int jj; ii+1 <= jj && jj < total;
			                           (pairs[ii] != pairs[jj] ? 1 : 0)))
			                     + (\sum int jj; index+1 <= jj && jj < c;
			                          (pairs[index] != pairs[jj] ? 1 : 0));
			@*/
			for (int c = index + 1; c < total; c++) {
				if (pairs[index] != pairs[c]) {
					count++;
				}
			}
		}
		return count;
	}
}