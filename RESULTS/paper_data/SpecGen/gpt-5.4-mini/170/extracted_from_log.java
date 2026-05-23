import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindRotationCount {

	//@ requires arr != null;
	//@ requires arr.length > 0;
	//@ ensures 0 <= \result && \result < arr.length;
	public static int findRotationCount(int[] arr) {
		int ret = 0;
		int stop = arr.length - 1;
		//@ maintaining 0 <= ret && ret <= arr.length;
		//@ maintaining -1 <= stop && stop < arr.length;
		//@ maintaining ret <= stop + 1;
		//@ decreases stop - ret + 1;
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