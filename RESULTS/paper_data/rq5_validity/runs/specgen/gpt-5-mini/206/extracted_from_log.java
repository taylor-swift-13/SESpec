import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindExtra {

	/*@ 
	  @ requires args != null && arr != null;
	  @ requires args.length >= 0 && arr.length >= 0;
	  @ 
	  @ ensures 0 <= \result && \result <= (args.length > arr.length ? args.length : arr.length);
	  @ 
	  @ // There exist final pointer positions ret0 and r0 reached by the loop such that
	  @ // the loop stopped because one of them reached the end, the result equals
	  @ // ret0 if ret0 did not reach args.length, otherwise it equals r0, and the
	  @ // two arrays are equal on all indices < min(ret0,r0).
 
	  @            0 <= ret0 && ret0 <= args.length &&
	  @            0 <= r0 && r0 <= arr.length &&
	  @            (ret0 >= args.length || r0 >= arr.length) &&
	  @            ((ret0 < args.length && \result == ret0) || (ret0 >= args.length && \result == r0)) &&
	  @            (\forall int k; 0 <= k && k < (ret0 < r0 ? ret0 : r0) ==> args[k] == arr[k])
	  @         );
	  @*/
	public static int findExtra(int[] args, int[] arr, int array) {
		int ret = 0;
		int r = 0;
		/*@
		  @ maintaining 0 <= ret && ret <= args.length;
		  @ maintaining 0 <= r && r <= arr.length;
		  @ maintaining (\forall int k; 0 <= k && k < (ret < r ? ret : r) ==> args[k] == arr[k]);
		  @ decreases (args.length - ret) + (arr.length - r);
		  @*/
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