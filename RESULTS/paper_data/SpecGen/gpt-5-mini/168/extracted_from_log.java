import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindRotationCount {

	//@ requires arr != null && arr.length > 0;
	//@ requires (\exists int k; 0 <= k && k < arr.length;
	//@            (\forall int i; 0 <= i && i < arr.length-1;
	//@                 arr[(k+i) % arr.length] < arr[(k+i+1) % arr.length]));
	//@ ensures 0 <= \result && \result < arr.length;
	//@ ensures (\forall int i; 0 <= i && i < arr.length; arr[\result] <= arr[i]);
	//@ ensures (\result == 0) <==> (\forall int i; 0 <= i && i < arr.length-1; arr[i] < arr[i+1]);
	//@ ensures \result > 0 ==> arr[\result-1] > arr[\result];
	public static int findRotationCount(int[] arr) {
		int ret = 0;
		int count = arr.length - 1;
		/*@
 
 
		  @    (\exists int k; 0 < k && k < arr.length &&
		  @         (\forall int i; 0 <= i && i < arr.length-1;
		  @              arr[(k+i) % arr.length] < arr[(k+i+1) % arr.length])
		  @         && ret <= k && k <= count)
		  @    ||
		  @    (\forall int i; 0 <= i && i < arr.length-1; arr[i] < arr[i+1])
		  @ );
		  @ decreases count - ret + 1;
		  @*/
		while (ret <= count) {
			int r = ret + (count - ret) / 2;
			if (r < count
					&& arr[r] > arr[r + 1]) {
				return r + 1;
			} else if (r > ret
					&& arr[r] < arr[r - 1]) {
				return r;
			}
			if (arr[r] >= arr[ret]) {
				ret = r + 1;
			} else {
				count = r - 1;
			}
		}
		return 0;
	}
}