import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindMissing {

    /*@ spec_public @*/
    /*@ 
      @ requires args != null;
      @ requires array >= 0;
      @ requires args.length >= array;
      @ 
      @ // If array is 0 or 1 the implementation returns 1.
      @ ensures (array == 0 || array == 1) ==> \result == 1;
      @ 
      @ // If there is an index k in 1..array that is the first position
      @ // where args[k-1] != k, then that k is returned.
      @ ensures (\exists int k; 1 <= k && k <= array &&
      @            (\forall int i; 1 <= i && i < k; args[i-1] == i) &&
      @            args[k-1] != k)
      @         ==> \result == (\min(\seqBox((new int[]{k}))));
      @ 
      @ // If all positions 1..array match, the method returns array.
      @ ensures (\forall int i; 1 <= i && i <= array; args[i-1] == i) ==> \result == array;
      @*/
	public static int findMissing(int[] args, int array) {
		int found = 1;
		if (array == 0 || array == 1) {
			return found;
		}
		//@ maintaining 1 <= remaining && remaining <= array + 1;
		//@ maintaining (\forall int i; 1 <= i && i < remaining; args[i-1] == i);
		//@ decreases array - remaining + 1;
		for (int remaining = 1; remaining <= array; remaining++) {
			if (args[remaining - 1] == remaining) {
				found = remaining;
			} else if (args[remaining - 1] != remaining) {
				return remaining;
			}
		}
		return found;
	}
}