import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindRotationCount {

	//@ requires arr.length > 0;
	//@ requires (\forall int i; 0 <= i && i < arr.length - 1; arr[i] <= arr[i + 1]) || (\exists int i; 0 <= i && i < arr.length - 1; arr[i] > arr[i + 1]);
	//@ ensures (\forall int i; 0 <= i && i < arr.length - 1; arr[i] <= arr[i + 1]) ==> \result == 0;
	//@ ensures (\exists int i; 0 <= i && i < arr.length - 1; arr[i] > arr[i + 1]) ==> arr[\result - 1] > arr[\result] && (\forall int i; \result <= i && i < arr.length - 1; arr[i] <= arr[i + 1]);
	public static int findRotationCount(int[] arr) {
		int ret = 0;
		int stop = arr.length - 1;
		//@ maintaining 0 <= ret && ret < stop && stop < arr.length;  
		//@ maintaining (\forall int i; 0 <= i && i < ret; arr[i] >= arr[0]);
		//@ maintaining (\forall int i; stop < i && i < arr.length; arr[i] >= arr[0]);
		//@ decreases stop - ret;
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