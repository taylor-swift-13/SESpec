import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindRotationCount {

	//@ requires arr != null && arr.length > 0;
	//@ ensures 0 <= \result && \result < arr.length;
 
	//@ ensures (\exists int i; \result <= i && i < arr.length; arr[i] <= arr[arr.length - 1]);  
	public static int findRotationCount(int[] arr) {
		int r = 0;
		int stop = arr.length - 1;
		//@ maintaining 0 <= r && r <= stop + 1 && stop < arr.length;
		//@ maintaining 0 <= stop + 1 && stop + 1 <= arr.length;
		//@ decreases stop - r + 1;
		while (r <= stop) {
			int i = r + (stop - r) / 2;
			if (i < stop
					&& arr[i] > arr[i + 1]) {
				return i + 1;
			} else if (i > r
					&& arr[i] < arr[i - 1]) {
				return i;
			}
			if (arr[i] >= arr[r]) {
				r = i + 1;
			} else {
				stop = i - 1;
			}
		}
		return 0;
	}
}