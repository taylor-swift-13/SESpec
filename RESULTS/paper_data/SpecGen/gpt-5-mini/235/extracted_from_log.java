import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class BigDiff {

	/*@ 
	  @ requires arr != null && arr.length > 0;
	  @ ensures (\exists int iMax, iMin; 0 < iMax && iMax < arr.length && 0 < iMin && iMin < arr.length ||  
	  @             (\forall int k; 0 <= k && k < arr.length; arr[k] <= arr[iMax] && arr[k] >= arr[iMin]) &&
	  @             \result == arr[iMax] - arr[iMin]);
 
	  @*/
	public static int bigDiff(int[] arr) {
		int result = arr[0];
		int sum = arr[0];
		/*@ 
		  @ maintaining 1 <= n && n <= arr.length;
		  @ maintaining (\forall int i; 0 <= i && i < n; arr[i] <= result);
		  @ maintaining (\exists int i; 0 <= i && i < n; arr[i] == result);
		  @ maintaining (\forall int i; 0 <= i && i < n; arr[i] >= sum);
		  @ maintaining (\exists int i; 0 <= i && i < n; arr[i] == sum);
		  @ decreases arr.length - n;
		  @*/
		for (int n = 1; n < arr.length; n++) {
			if (arr[n] > result) {
				result = arr[n];
			}
			if (arr[n] < sum) {
				sum = arr[n];
			}
		}
		return result - sum;
	}
}