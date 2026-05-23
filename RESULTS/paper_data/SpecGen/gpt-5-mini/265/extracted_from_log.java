import java.io.*;
import java.lang.*;
import java.math.*;

class GetOddOccurrence {

	/*@
	  @ requires ints != null;
	  @ requires 0 <= array && array <= ints.length;
	  @ // The method does not modify the input array
	  @ ensures (\forall int i; 0 <= i && i < ints.length; ints[i] == \old(ints[i]));
	  @ // The result equals the value at the last index p < array for which
	  @ // the number of odd elements in the prefix [0..p] is odd, if such p exists;
	  @ // otherwise the result is 0.
	  @ ensures (
	  @   (\exists int p; 0 <= p && p < array &&
	  @       (\num_of int k; 0 <= k && k <= p; (ints[k] % 2 != 0); 1) % 2 == 1 &&
	  @       (\forall int q; p < q && q < array ==>
	  @           (\num_of int k; 0 <= k && k <= q; (ints[k] % 2 != 0); 1) % 2 == 0) &&
	  @       \result == ints[p])
	  @ ) || (
	  @   (\forall int p; 0 <= p && p < array ==>
	  @       (\num_of int k; 0 <= k && k <= p; (ints[k] % 2 != 0); 1) % 2 == 0) &&
	  @   \result == 0
	  @ );
	  @*/
	public static int getOddOccurrence(int[] ints, int array) {
		int ret = 0;
		int start = 0;
		/*@
		  @ maintaining 0 <= index && index <= array;
		  @ maintaining start == (\num_of int k; 0 <= k && k < index; (ints[k] % 2 != 0); 1);
		  @ // ret describes the last odd-occurrence value (within the processed prefix)
		  @ maintaining (
		  @   (\exists int p; 0 <= p && p < index &&
		  @       (\num_of int k; 0 <= k && k <= p; (ints[k] % 2 != 0); 1) % 2 == 1 &&
		  @       (\forall int q; p < q && q < index ==>
		  @           (\num_of int k; 0 <= k && k <= q; (ints[k] % 2 != 0); 1) % 2 == 0) &&
		  @       ret == ints[p])
		  @ ) || (
		  @   (\forall int p; 0 <= p && p < index ==>
		  @       (\num_of int k; 0 <= k && k <= p; (ints[k] % 2 != 0); 1) % 2 == 0) &&
		  @   ret == 0
		  @ );
		  @ decreases array - index;
		  @*/
		for (int index = 0; index < array; index++) {
			if (ints[index] % 2 != 0) {
				start++;
				if (start % 2 != 0) {
					ret = ints[index];
				}
			}
		}
		return ret;
	}
}