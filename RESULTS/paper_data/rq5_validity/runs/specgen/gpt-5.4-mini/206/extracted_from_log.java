import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindExtra {

	//@ requires args != null && arr != null;
 
 
	public static int findExtra(int[] args, int[] arr, int array) {
		int ret = 0;
		int r = 0;
		//@ maintaining 0 <= ret && ret <= args.length;
		//@ maintaining 0 <= r && r <= arr.length;
		//@ decreases (args.length - ret) + (arr.length - r);
		while (ret < args.length && r < arr.length) {
			if (args[ret] < arr[r]) {
				ret++;
			} else if (args[ret] > arr[r]) {
				r++;
			} else {
				ret++;
				r++;
			}
		}
		return ret < args.length ? ret : r;
	}
}