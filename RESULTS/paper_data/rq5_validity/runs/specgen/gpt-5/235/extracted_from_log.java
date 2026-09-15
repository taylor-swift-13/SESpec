import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class BigDiff {

    /*@ spec_public @*/
    /*@
      @ public normal_behavior
      @ requires arr != null && arr.length > 0;
      @ assignable \nothing;
      @ ensures (\exists int i, j; 0 <= i && i < arr.length && 0 <= j && j < arr.length;
      @            (\forall int k; 0 <= k && k < arr.length; arr[i] >= arr[k] && arr[j] <= arr[k]) &&
      @            \result == arr[i] - arr[j]);
      @ ensures \result >= 0;
      @*/
	public static int bigDiff(int[] arr) {
		int result = arr[0];
		int sum = arr[0];
        //@ maintaining 1 <= n && n <= arr.length;
        //@ maintaining (\forall int k; 0 <= k && k < n; result >= arr[k]);
        //@ maintaining (\exists int k; 0 <= k && k < n; result == arr[k]);
        //@ maintaining (\forall int k; 0 <= k && k < n; sum <= arr[k]);
        //@ maintaining (\exists int k; 0 <= k && k < n; sum == arr[k]);
        //@ decreases arr.length - n;
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