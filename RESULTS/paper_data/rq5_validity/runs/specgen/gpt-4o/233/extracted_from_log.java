import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class BigDiff {

	/*@ spec_public @*/ 
	public static int bigDiff(int[] arr) {
		//@ requires arr != null && arr.length > 0;
 
		//@ assume arr.length > 0; // Ensure the array has at least one element
		//@ assume 0 < arr.length; // Ensure index 0 is valid
		int result = arr[0];
		//@ assume 0 < arr.length; // Ensure index 0 is valid
		int num = arr[0];
		//@ maintaining 1 <= n && n <= arr.length;
 
 
		//@ decreases arr.length - n;
		for (int n = 1; n < arr.length; n++) {
			//@ assume 0 <= n && n < arr.length; // Ensure index n is valid
			if (arr[n] > result) {
				result = arr[n];
			}
			if (arr[n] < num) {
				num = arr[n];
			}
		}
		return result - num;
	}
}