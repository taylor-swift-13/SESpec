import java.io.*;
import java.lang.*;
import java.math.*;

class GetOddOccurrence {

	/*@ 
	  @ requires array != null;
	  @ requires 0 <= Array && Array <= array.length;
	  @ 
	  @ // total number of odd elements in array[0..Array-1]
	  @ // We express the count using a sum of 1 for each odd element.
	  @
	  @ ensures (\sum int p; 0 <= p && p < Array; (array[p] % 2 != 0 ? 1 : 0)) == 0 ==> \result == 0;
	  @ 
 
	  @   (\exists int k; 0 <= k && k < Array &&
	  @        array[k] % 2 != 0 &&
	  @        ((\sum int p; 0 <= p && p <= k; (array[p] % 2 != 0 ? 1 : 0)) % 2) == 1 &&
	  @        // no later index < Array has the "odd-position" property
	  @        (\forall int l; k < l && l < Array ==>
	  @            ! ( array[l] % 2 != 0 &&
	  @                ((\sum int p; 0 <= p && p <= l; (array[p] % 2 != 0 ? 1 : 0)) % 2) == 1 )
	  @        )
	  @        && \result == array[k]
	  @   );
	  @*/
	public static int getOddOccurrence(int[] array, int Array) {
		int ret = 0;
		int start = 0;
		/*@
		  @ maintaining 0 <= index && index <= Array;
 
		  @ // ret is either 0 (no qualifying odd seen so far) or equals the last seen odd element
		  @ // whose position among odds encountered so far is odd.
		  @ maintaining (start == 0) ==> ret == 0;
		  @ maintaining (start > 0) ==>
		  @   (\exists int k; 0 <= k && k < index &&
		  @        array[k] % 2 != 0 &&
		  @        ((\sum int p; 0 <= p && p <= k; (array[p] % 2 != 0 ? 1 : 0)) % 2) == 1 &&
		  @        (\forall int l; k < l && l < index ==>
		  @            ! ( array[l] % 2 != 0 &&
		  @                ((\sum int p; 0 <= p && p <= l; (array[p] % 2 != 0 ? 1 : 0)) % 2) == 1 )
		  @        )
		  @        && ret == array[k]
		  @   );
		  @ decreases Array - index;
		  @*/
		for (int index = 0; index < Array; index++) {
			if (array[index] % 2 != 0) {
				start++;
				if (start % 2 != 0) {
					ret = array[index];
				}
			}
		}
		return ret;
	}
}