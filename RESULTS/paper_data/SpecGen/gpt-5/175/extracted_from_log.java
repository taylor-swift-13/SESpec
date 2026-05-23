import java.io.*;
import java.lang.*;
import java.util.*;

class FindLastOccurrence {

	/*@ requires arr != null;
	  @ requires (\forall int p, q; 0 <= p && p < q && q < arr.length; arr[p] <= arr[q]);
	  @ ensures (\result == -1) <==> (\forall int k; 0 <= k && k < arr.length; arr[k] != Array);
	  @ ensures 0 <= \result && \result < arr.length ==>
	  @           (arr[\result] == Array &&
	  @            (\forall int k; \result < k && k < arr.length; arr[k] != Array));
	  @*/
	public static int findLastOccurrence(int[] arr, int Array) {
		int i = 0;
		int hi = arr.length - 1;
		int end = 0;
		/*@ maintaining arr != null &&
		  @            (\forall int p, q; 0 <= p && p < q && q < arr.length; arr[p] <= arr[q]);
		  @ maintaining 0 <= i && i <= arr.length;
		  @ maintaining -1 <= hi && hi < arr.length;
		  @ maintaining i <= hi + 1;
		  @ maintaining (\forall int k; 0 <= k && k < i; arr[k] <= Array);
		  @ maintaining (\forall int k; hi < k && k < arr.length; arr[k] > Array);
		  @ decreases hi - i + 1;
		  @*/
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