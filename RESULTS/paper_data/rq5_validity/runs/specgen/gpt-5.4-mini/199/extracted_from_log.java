import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class CatalanNumber {

	/*@ requires number >= 0;
 
 
	  @*/
	public static int catalanNumber(int number) {
		int[] arr = new int[number + 1];
		arr[0] = 1;
		/*@ maintaining 1 <= c && c <= number + 1;
		  @ maintaining arr.length == number + 1;
 
		  @ decreasing number - c + 1;
		  @*/
		for (int c = 1; c <= number; c++) {
			arr[c] = 0;
			/*@ maintaining 0 <= n && n <= c;
 
			  @ decreasing c - n;
			  @*/
			for (int n = 0; n < c; n++) {
				arr[c] += arr[n]
						* arr[c - n - 1];
			}
		}
		return arr[number];
	}
}