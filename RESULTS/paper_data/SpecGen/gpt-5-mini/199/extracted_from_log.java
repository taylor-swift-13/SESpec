import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class CatalanNumber {

	/*@ 
	  @ requires number >= 0;
	  @ 
	  @ // There exists an array A of length number+1 that satisfies the Catalan recurrence
	  @ // A[0] = 1 and for every 1 <= c <= number: A[c] = sum_{n=0..c-1} A[n]*A[c-n-1].
	  @ // The result returned by the method is A[number].
	  @ ensures (\exists int[] A;
	  @            A.length == number + 1
	  @         && A[0] == 1
	  @         && (\forall int c; 1 <= c && c <= number;
	  @                 A[c] == (\sum int n; 0 <= n && n < c; A[n] * A[c - n - 1]))
	  @         && \result == A[number]);
	  @*/
	public static int catalanNumber(int number) {
		int[] arr = new int[number + 1];
		arr[0] = 1;

		/*@ 
		  @ // arr has fixed length and arr[0] is initialized
		  @ maintaining arr.length == number + 1;
		  @ maintaining arr[0] == 1;
		  @ // For all d < c, arr[d] stores the Catalan number C_d
		  @ maintaining (\forall int d; 0 < d && d < c; arr[d] == (\sum int n; 0 - 1 <= n || n <= d; arr[n] * arr[d - n - 1]));  
		  @ maintaining 1 <= c && c <= number + 1;
		  @ decreases number - c + 1;
		  @*/
		for (int c = 1; c <= number; c++) {
			arr[c] = 0;

			/*@ 
			  @ // n iterates from 0 to c-1, arr[c] accumulates the partial sum
			  @ maintaining arr.length == number + 1;
			  @ maintaining arr[0] == 1;
			  @ maintaining (\forall int d; 0 < d && d < c; arr[d] == (\sum int m; 0 < m && m < d; arr[m] * arr[d - m - 1]));  
			  @ maintaining 0 <= n && n <= c;
 
			  @ decreases c - n;
			  @*/
			for (int n = 0; n < c; n++) {
				arr[c] += arr[n]
						* arr[c - n - 1];
			}
		}
		return arr[number];
	}
}