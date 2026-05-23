import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindRotationCount {

	/*@ spec_public @*/
	/*@ public normal_behavior
	  @ requires arr != null && arr.length > 0
	  @   && (\exists int p; 0 <= p && p < arr.length &&
	  @         (\forall int i; 0 <= i && i < arr.length-1;
	  @             arr[(p+i) % arr.length] <= arr[(p+i+1) % arr.length]));
	  @ ensures 0 <= \result && \result < arr.length;
	  @ ensures (\forall int i; 0 <= i && i < arr.length; arr[\result] <= arr[i]);
	  @*/
	public static int findRotationCount(int[] arr) {
		int ret = 0;
		int stop = arr.length - 1;
		/*@ 
		  @ maintaining 0 <= ret && ret <= stop + 1 && stop < arr.length;
		  @ maintaining (\exists int m; 0 <= m && m < arr.length &&
		  @                (\forall int i; 0 <= i && i < arr.length; arr[m] <= arr[i]) &&
		  @                ret <= m && m <= stop);
		  @ decreases stop - ret;
		  @*/
		while (ret <= stop) {
			int r = ret + (stop - ret) / 2;
			if (r < stop
					&& arr[r] > arr[r + 1]) {
				return r + 1;
			} else if (r > ret
					&& arr[r] < arr[r - 1]) {
				return r;
			}
			if (arr[r] >= arr[ret]) {
				ret = r + 1;
			} else {
				stop = r - 1;
			}
		}
		return 0;
	}
}