import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindExtra {

	//@ requires args != null && arr != null;
	//@ requires args.length == arr.length + 1;
	//@ ensures 0 <= \result && \result < args.length;
 
	public static int findExtra(int[] args, int[] arr, int Array) {
		int ret = 0;
		int len = 0;
		//@ maintaining 0 <= ret && ret <= args.length;
		//@ maintaining 0 <= len && len <= arr.length;
		//@ decreases (args.length - ret) + (arr.length - len);
		while (ret < args.length && len < arr.length) {
			if (args[ret] < arr[len]) {
				ret++;
			} else if (args[ret] > arr[len]) {
				len++;
			} else {
				ret++;
				len++;
			}
		}
		return ret < args.length ? ret : len;
	}
}