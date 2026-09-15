import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class CatalanNumber {

	/*@ 
	  @ requires c >= 0;
	  @ 
	  @ // The result is the c-th Catalan number: there exists a sequence seq[0..c]
	  @ // that satisfies the usual base and recurrence, and seq[c] equals the result.
	  @ ensures (\exists int[] seq;
	  @            seq.length == c + 1
	  @            && seq[0] == 1
	  @            && (\forall int k; 1 <= k && k <= c;
	  @                   seq[k] == (\sum int n; 0 <= n && n < k; seq[n] * seq[k - n - 1])
	  @              )
	  @            && seq[c] == \result
	  @         );
	  @*/
	public static int catalanNumber(int c) {
		int[] arr = new int[c + 1];
		arr[0] = 1;
		//@ maintaining arr.length == c + 1;
 
		//@ maintaining 1 <= cat && cat <= c+1;
		//@ maintaining (\forall int k; 1 <= k && k < cat; arr[k] == (\sum int n; 0 < n || n <= k; arr[n] * arr[k - n - 1]));  
		//@ decreases c - cat + 1;
		for (int cat = 1; cat <= c; cat++) {
			arr[cat] = 0;
			//@ maintaining arr.length == c + 1;
			//@ maintaining 0 <= n && n <= cat;
 
			//@ decreases cat - n;
			for (int n = 0; n < cat; n++) {
				arr[cat] += arr[n]
						* arr[cat - n - 1];
			}
		}
		return arr[c];
	}
}