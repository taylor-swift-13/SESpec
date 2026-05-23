import java.io.*;
import java.lang.*;
import java.math.*;

class GetOddOccurrence {

	/*@ 
	  @ requires args != null;
	  @ requires 0 <= array && array <= args.length;
	  @ 
	  @ // If the number of odd elements in the prefix [0..array-1] is even, result is 0
 
	  @ 
	  @ // If the number of odd elements in the prefix is odd, result equals the element
	  @ // at the last index j < array for which the cumulative number of odds up to j is odd.
 
	  @   (\exists int j; 0 <= j && j < array;
	  @       args[j] % 2 != 0 &&
	  @       ((\num_of int i; 0 <= i && i <= j; args[i] % 2 != 0) % 2) == 1 &&
	  @       (\forall int k; j < k && k < array;
	  @           ((\num_of int i; 0 <= i && i <= k; args[i] % 2 != 0) % 2) == 0) &&
	  @       \result == args[j]);
	  @*/
	public static int getOddOccurrence(int[] args, int array) {
		int ret = 0;
		int start = 0;
		/*@
		  @ // Loop invariants:
		  @ //  - index ranges 0..array
		  @ //  - start equals the number of odd elements in args[0..index-1]
		  @ //  - ret is 0 when the cumulative count of odds so far is even,
		  @ //    otherwise ret equals the last array element (among seen ones) where
		  @ //    the cumulative count was odd.
		  @ maintaining 0 <= index && index <= array;
 
		  @ maintaining ((\num_of int i; 0 <= i && i < index; args[i] % 2 != 0) % 2 == 0 ==> ret == 0)
		  @          || ((\num_of int i; 0 <= i && i < index; args[i] % 2 != 0) % 2 == 1
		  @               ==> (\exists int j; 0 <= j && j < index;
		  @                       args[j] % 2 != 0 &&
		  @                       ((\num_of int i; 0 <= i && i <= j; args[i] % 2 != 0) % 2) == 1 &&
		  @                       (\forall int k; j < k && k < index;
		  @                           ((\num_of int i; 0 <= i && i <= k; args[i] % 2 != 0) % 2) == 0) &&
		  @                       ret == args[j]));
		  @ decreases array - index;
		  @*/
		for (int index = 0; index < array; index++) {
			if (args[index] % 2 != 0) {
				start++;
				if (start % 2 != 0) {
					ret = args[index];
				}
			}
		}
		return ret;
	}
}