import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindRotationCount {

	//@ requires arr != null && arr.length > 0;
	//@ ensures 0 <= \result && \result < arr.length;
	//@ ensures (\exists int i; 0 < i && i < \result; arr[i] + 1 >= arr[\result]);  
	//@ ensures (\exists int i; \result <= i && i < arr.length; arr[i] >= arr[\result]);  
	public static int findRotationCount(int[] arr) {
		int ret = 0;
		int count = arr.length - 1;
		//@ maintaining 0 <= ret && ret <= count + 1 && count < arr.length;
		//@ maintaining 0 <= count && count < arr.length || ret == count + 1;
		//@ maintaining (\exists int i; 0 <= i && i <= ret; arr[i] >= arr[ret]);  
		//@ maintaining (\exists int i; count <= i && i < arr.length; arr[i] >= arr[count > 0 ? count : 0]);  
		//@ decreases count - ret + 1;
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