import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindExtra {

	/*@ 
	  @ requires args != null && arr != null;
	  @ requires (\forall int i; 0 <= i && i + 1 < args.length; args[i] <= args[i+1]);
	  @ requires (\forall int i; 0 <= i && i + 1 < arr.length; arr[i] <= arr[i+1]);
	  @ ensures 0 <= \result && (\result <= args.length || \result <= arr.length);
	  @*/
	public static int findExtra(int[] args, int[] arr, int array) {
		int ret = 0;
		int len = 0;
		/*@ 
		  @ maintaining 0 <= ret && 0 <= len;
		  @ maintaining ret <= args.length && len <= arr.length;
		  @ maintaining ret + len <= args.length + arr.length;
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