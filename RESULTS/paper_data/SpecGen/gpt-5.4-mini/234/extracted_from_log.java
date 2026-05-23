import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class BigDiff {

	/*@ requires arr != null && arr.length > 0;
 
 
	  @                    - (\min int i; 0 <= i && i < arr.length; arr[i]);
	  @*/
	public static int bigDiff(int[] arr) {
		int big = arr[0];
		int sum = arr[0];
		/*@ maintaining 1 <= n && n <= arr.length;
		  @ maintaining (\forall int i; 0 <= i && i < n; big >= arr[i]);
		  @ maintaining (\forall int i; 0 <= i && i < n; sum <= arr[i]);
		  @ decreasing arr.length - n;
		  @*/
		for (int n = 1; n < arr.length; n++) {
			if (arr[n] > big) {
				big = arr[n];
			}
			if (arr[n] < sum) {
				sum = arr[n];
			}
		}
		return big - sum;
	}
}