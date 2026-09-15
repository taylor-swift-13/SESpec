import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindKth {

    //@ requires arr1 != null && arr != null;
    //@ requires 0 <= Array && Array <= arr1.length;
    //@ requires 0 <= n && n <= arr.length;
    //@ requires 1 <= p && p <= Array + n;
    //@ requires (\forall int i; 0 <= i && i + 1 < Array; arr1[i] <= arr1[i+1]);
    //@ requires (\forall int j; 0 <= j && j + 1 < n; arr[j] <= arr[j+1]);
    //@ ensures (\exists int i; 0 <= i && i < Array; \result == arr1[i]) || (\exists int j; 0 <= j && j < n; \result == arr[j]);
    //@ ensures ((\num_of int i; 0 <= i && i < Array; arr1[i] < \result)
    //@          + (\num_of int j; 0 <= j && j < n; arr[j] < \result)) < p;
    //@ ensures ((\num_of int i; 0 <= i && i < Array; arr1[i] <= \result)
    //@          + (\num_of int j; 0 <= j && j < n; arr[j] <= \result)) >= p;
	public static int findKth(int[] arr1, int[] arr, int Array, int n, int p) {
		int result = 0;
		int tmp = 0;

        //@ maintaining 0 <= count && count <= p;
        //@ maintaining 0 <= result && result <= Array;
        //@ maintaining 0 <= tmp && tmp <= n;
        //@ maintaining result + tmp == count;
        //@ maintaining (\forall int i; 0 <= i && i < result; (\forall int j; tmp <= j && j < n; arr1[i] <= arr[j]));
        //@ maintaining (\forall int j; 0 <= j && j < tmp; (\forall int i; result <= i && i < Array; arr[j] <= arr1[i]));
        //@ decreases p - count;
		for (int count = 0; count < p; count++) {
			if (result < Array
					&& (tmp >= n || arr1[result] <= arr[tmp])) {
				if (count == p - 1) {
					return arr1[result];
				}
				result++;
			} else {
				if (count == p - 1) {
					return arr[tmp];
				}
				tmp++;
			}
		}
		return -1;
	}
}