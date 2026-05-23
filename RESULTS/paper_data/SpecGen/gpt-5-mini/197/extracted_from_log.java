import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class CatalanNumber {

	/*@ 
	  @ requires n >= 0;
	  @ 
	  @ // There exists an integer array A of length n+1 that satisfies the
	  @ // Catalan recurrence (A[0] = 1 and for c>=1, A[c] = sum_{k=0..c-1} A[k]*A[c-k-1])
	  @ // and the method result equals A[n].
	  @ ensures (\exists int[] A;
	  @            A != null &&
	  @            A.length == n + 1 &&
	  @            A[0] == 1 &&
	  @            (\forall int c; 1 <= c && c <= n; A[c] == (\sum int k; 0 <= k && k < c; A[k] * A[c - k - 1])) &&
	  @            A[n] == \result);
	  @ 
	  @ // Non-negativity of Catalan numbers (for int arithmetic used here)
	  @ ensures \result >= 0;
	  @*/
	public static int catalanNumber(int n) {
		int[] arr = new int[n + 1];
		arr[0] = 1;
		/*@ 
		  @ // Invariant: arr has the allocated length
 
		  @ // arr[0] stays 1
 
		  @ // For the outer loop index c: for all i with 0 <= i < c the value arr[i]
		  @ // satisfies the Catalan recurrence:
		  @ //   if i == 0 then arr[0] == 1
		  @ //   if 1 <= i < c then arr[i] == sum_{t=0..i-1} arr[t] * arr[i-t-1]
 
		  @                (i == 0 ? arr[0] == 1 : arr[i] == (\sum int t; 0 <= t && t < i; arr[t] * arr[i - t - 1])));
		  @ decreases n - c + 1;
		  @*/
		for (int c = 1; c <= n; c++) {
			arr[c] = 0;
			/*@
			  @ // Inner loop invariant:
			  @ // k ranges from 0..c and arr[c] equals the partial sum
			  @ // arr[c] == sum_{t=0..k-1} arr[t] * arr[c-t-1]
			  @ maintaining 0 <= k && k <= c;
 
			  @ decreases c - k;
			  @*/
			for (int k = 0; k < c; k++) {
				arr[c] += arr[k]
						* arr[c - k - 1];
			}
		}
		return arr[n];
	}
}