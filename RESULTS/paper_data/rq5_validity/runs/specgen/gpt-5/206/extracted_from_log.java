import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindExtra {

    /*@
      @ requires args != null && arr != null;
      @ assignable \nothing;
      @ ensures 0 <= \result && \result <= (args.length >= arr.length ? args.length : arr.length);
      @ ensures (args.length == 0 || arr.length == 0) ==> \result == 0;
      @*/
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