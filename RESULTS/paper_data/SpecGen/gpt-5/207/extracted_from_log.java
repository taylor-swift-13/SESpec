import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindExtra {

	/*@
	  @ requires args != null && arr != null;
	  @ assignable \nothing;
	  @ ensures 0 <= \result && (\result <= args.length || \result <= arr.length);
	  @ ensures (args.length == 0 || arr.length == 0) ==> \result == 0;
	  @ ensures (args.length == arr.length && (\forall int i; 0 <= i && i < args.length; args[i] == arr[i])) ==> \result == args.length;
	  @*/
	public static int findExtra(int[] args, int[] arr, int array) {
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