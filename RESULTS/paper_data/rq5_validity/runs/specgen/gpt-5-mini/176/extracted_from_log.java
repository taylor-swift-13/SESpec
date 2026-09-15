import java.io.*;
import java.lang.*;
import java.util.*;

class FindLastOccurrence {

    /*@ spec_public @*/
    /*@ 
      @ requires arr != null;
      @ // array must be sorted non-decreasingly
      @ requires (\forall int i, j; 0 <= i && i <= j && j < arr.length; arr[i] <= arr[j]);
      @ 
      @ // If result is -1 then no element equals the target; otherwise result is a valid last index with that value
      @ ensures (\result == -1) <==> (\forall int i; 0 <= i && i < arr.length; arr[i] != array);
      @ ensures 0 <= \result && \result < arr.length ==> (arr[\result] == array 
      @           && (\forall int i; \result < i && i < arr.length; arr[i] != array));
      @*/
	public static int findLastOccurrence(int[] arr, int array) {
		int found = 0;
		int hi = arr.length - 1;
		int end = 0;
		/*@ 
		  @ maintaining 0 <= found && found <= arr.length;
		  @ maintaining -1 <= hi && hi < arr.length;
		  @ // all indices strictly less than 'found' are <= target
		  @ maintaining (\forall int i; 0 <= i && i < found; arr[i] <= array);
		  @ // all indices strictly greater than 'hi' are > target
		  @ maintaining (\forall int i; hi < i && i < arr.length; arr[i] > array);
		  @ decreases hi - found + 1;
		  @*/
		while (found <= hi) {
			end = (found + hi) / 2;
			if (arr[end] == array) {
				if (end == arr.length - 1
						|| arr[end + 1] != array) {
					return end;
				} else {
					found = end + 1;
				}
			} else if (arr[end] < array) {
				found = end + 1;
			} else {
				hi = end - 1;
			}
		}
		return -1;
	}
}