import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindRotationCount {

	/*@ 
	  @ requires arr != null;
	  @ requires arr.length > 0;
	  @ // array is a rotation of a strictly increasing sequence
	  @ requires (\exists int s; 0 <= s && s < arr.length;
	  @             (\forall int i; 0 <= i && i < arr.length-1;
	  @                 arr[(i + s) % arr.length] < arr[(i + s + 1) % arr.length]));
	  @ 
	  @ ensures 0 <= \result && \result < arr.length;
	  @ // result points to a minimum element
	  @ ensures (\forall int k; 0 <= k && k < arr.length; arr[\result] <= arr[k]);
	  @ // and it is the pivot (previous element is greater, unless result == 0)
	  @ ensures (\result == 0) || arr[\result] < arr[\result - 1];
	  @*/
	public static int findRotationCount(int[] arr) {
		int r = 0;
		int stop = arr.length - 1;
		/*@ 
 
 
		  @ // the true pivot (index of a minimal element) always lies in [r, stop+1]
 
		  @               (\forall int k; 0 <= k && k < arr.length; arr[p] <= arr[k]) &&
		  @               r <= p && p <= stop + 1);
		  @ decreases stop - r + 1;
		  @*/
		while (r <= stop) {
			int i = r + (stop - r) / 2;
			if (i < stop
					&& arr[i] > arr[i + 1]) {
				return i + 1;
			} else if (i > r
					&& arr[i] < arr[i - 1]) {
				return i;
			}
			if (arr[i] >= arr[r]) {
				r = i + 1;
			} else {
				stop = i - 1;
			}
		}
		return 0;
	}
}