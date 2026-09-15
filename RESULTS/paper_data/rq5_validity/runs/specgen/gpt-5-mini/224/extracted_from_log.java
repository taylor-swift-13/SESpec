import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindMissing {

	/*@ 
	  @ requires args != null;
	  @ requires array >= 0;
	  @ requires args.length >= array;
	  @ 
	  @ // If array is 0 or 1, method returns 1 (matches implementation's early return).
	  @ ensures (array == 0 || array == 1) ==> \result == 1;
	  @ 
	  @ // If there exists a mismatch in 1..array, result is the smallest such index k.
 
	  @          (1 <= \result && \result <= array &&
	  @           args[\result-1] != \result &&
	  @           (\forall int j; 1 <= j && j < \result; args[j-1] == j));
	  @ 
	  @ // If all elements 1..array match their indices, then result equals array
	  @ // (note: array==0 or 1 already handled above).
	  @ ensures (\exists int k; 1 < k && k < array; args[k-1] == k && array > 2) ==> \result == array;  
	  @ 
	  @ // Result is always at least 1 (by the implementation).
	  @ ensures \result >= 1;
	  @*/
	public static int findMissing(int[] args, int array) {
		int found = 1;
		if (array == 0 || array == 1) {
			return found;
		}
		//@ maintaining 1 <= num && num <= array + 1;
		//@ maintaining (\forall int j; 1 < j && j < num; args[j-1] == j);  
		//@ maintaining ((num > 1 && found == num-1) || (num == 1 && found == 1));
		//@ decreases array - num + 1;
		for (int num = 1; num <= array; num++) {
			if (args[num - 1] == num) {
				found = num;
			} else if (args[num - 1] != num) {
				return num;
			}
		}
		return found;
	}
}