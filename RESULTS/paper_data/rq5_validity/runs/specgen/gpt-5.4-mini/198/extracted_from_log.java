import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class CatalanNumber {

	/*@ requires c >= 0;
 
	  @ ensures c == 0 ==> \result == 1;
 
	  @*/
	public static int catalanNumber(int c) {
		int[] arr = new int[c + 1];
		arr[0] = 1;
		/*@ maintaining 1 <= cat && cat <= c + 1;
		  @ maintaining arr.length == c + 1;
		  @ maintaining arr[0] == 1;
		  @ decreases c - cat + 1;
		  @*/
		for (int cat = 1; cat <= c; cat++) {
			arr[cat] = 0;
			/*@ maintaining 0 <= n && n <= cat;
			  @ maintaining arr.length == c + 1;
			  @ maintaining arr[0] == 1;
 
			  @ decreases cat - n;
			  @*/
			for (int n = 0; n < cat; n++) {
				arr[cat] += arr[n]
						* arr[cat - n - 1];
			}
		}
		return arr[c];
	}
}