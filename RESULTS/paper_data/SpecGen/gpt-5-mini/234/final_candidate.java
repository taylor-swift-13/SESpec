import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class BigDiff {

    /*@ public normal_behavior
      @   requires arr != null && arr.length > 0;
      @   ensures (\exists int imax; 0 < imax && imax < arr.length ||  
      @               (\forall int i; 0 <= i && i < arr.length; arr[i] <= arr[imax]) &&
      @               (\exists int imin; 0 <= imin && imin < arr.length &&
      @                   (\forall int j; 0 <= j && j < arr.length; arr[imin] <= arr[j]) &&
      @                   arr[imax] - arr[imin] == \result));
      @*/
	public static int bigDiff(int[] arr) {
		int big = arr[0];
		int sum = arr[0];
		/*@ maintaining 1 <= n && n <= arr.length;
		  @ maintaining (\forall int i; 0 <= i && i < n; arr[i] <= big);
		  @ maintaining (\exists int i; 0 <= i && i < n; arr[i] == big);
		  @ maintaining (\forall int i; 0 <= i && i < n; sum <= arr[i]);
		  @ maintaining (\exists int i; 0 <= i && i < n; arr[i] == sum);
		  @ decreases arr.length - n;
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
