import java.io.*;
import java.lang.*;
import java.util.*;

class FindLastOccurrence {

	/*@ spec_public @*/
	//@ requires arr != null;
	//@ requires (\forall int p; 0 <= p && p + 1 < arr.length; arr[p] <= arr[p+1]); // array must be non-decreasing
	//@ ensures \result == -1 <==> (\forall int j; 0 <= j && j < arr.length; arr[j] != Array);
	//@ ensures 0 <= \result && \result < arr.length ==>
	//@           (arr[\result] == Array && (\result == arr.length - 1 || arr[\result+1] != Array));
	public static int findLastOccurrence(int[] arr, int Array) {
		int i = 0;
		int hi = arr.length - 1;
		int end = 0;
		//@ maintaining 0 <= i && i <= arr.length;
		//@ maintaining -1 <= hi && hi < arr.length;
		//@ maintaining (\forall int k; 0 <= k && k < i; arr[k] <= Array);
		//@ maintaining (\forall int k; hi < k && k < arr.length; arr[k] > Array);
		//@ maintaining (\forall int k; 0 <= k && k < arr.length && arr[k] == Array; k <= hi);
		//@ maintaining (i <= hi) ==> (i <= end && end <= hi);
		//@ decreases hi - i + 1;
		while (i <= hi) {
			end = (i + hi) / 2;
			if (arr[end] == Array) {
				if (end == arr.length - 1
						|| arr[end + 1] != Array) {
					return end;
				} else {
					i = end + 1;
				}
			} else if (arr[end] < Array) {
				i = end + 1;
			} else {
				hi = end - 1;
			}
		}
		return -1;
	}
}