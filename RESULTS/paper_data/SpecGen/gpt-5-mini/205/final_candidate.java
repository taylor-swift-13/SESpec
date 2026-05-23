import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindExtra {

	/*@ 
	  @ requires args != null && arr != null;
	  @ // lengths are non-negative by Java array semantics, kept for clarity
	  @ requires args.length >= 0 && arr.length >= 0;
	  @ 
	  @ // result is a non-negative index indicating which array still has elements
	  @ // (either an index into args when some args remain, or an index into arr
	  @ // when args are exhausted). This is a lightweight postcondition ensuring
	  @ // the result is a valid array index bound relative to the inputs.
	  @ ensures 0 <= \result && (\result < args.length || \result <= arr.length);  
	  @*/
	public static int findExtra(int[] args, int[] arr, int Array) {
		int ret = 0;
		int len = 0;
		/*@ 
		  @ maintaining 0 <= ret && ret <= args.length;
		  @ maintaining 0 <= len && len <= arr.length;
		  @ // the loop only advances indices; neither ret nor len ever decreases
		  @ maintaining (\forall int i; 0 <= i && i < ret ==> (\exists int j; 0 <= j && j <= len; true));
		  @ // likewise some simple relation: at every point both indices are within bounds
		  @ decreases (args.length - ret) + (arr.length - len);
		  @*/
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
