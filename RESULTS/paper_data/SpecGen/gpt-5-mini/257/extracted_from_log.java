import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class LeftInsertion {

	/*@
	  spec_public;
	  requires args != null;
	  requires (\forall int i; 0 <= i && i+1 < args.length; args[i] <= args[i+1]); // array is sorted non-decreasing
	  ensures 0 <= \result && \result <= args.length;
	  ensures (\exists int j; 0 <= j && j < args.length; args[j] == array) ==>
	          (\result < args.length && args[\result] == array &&
	           (\forall int k; 0 <= k && k < \result; args[k] < array));
	  ensures (\forall int j; 0 <= j && j < args.length; args[j] != array) ==>
	          ((\forall int k; 0 <= k && k < \result; args[k] < array) &&
	           (\forall int k; \result <= k && k < args.length; args[k] > array));
	@*/
	public static int leftInsertion(int[] args, int array) {
		int ret = 0;
		int top = args.length - 1;
		//@ maintaining 0 <= ret && ret <= args.length;
		//@ maintaining -1 <= top && top < args.length;
		//@ maintaining (\forall int k; 0 <= k && k < ret; args[k] < array);
		//@ maintaining (\forall int k; top < k && k < args.length; args[k] > array);
		//@ decreases top - ret + 1;
		while (ret <= top) {
			int i = (ret + top) / 2;
			if (args[i] == array) {
				return i;
			} else if (args[i] < array) {
				ret = i + 1;
			} else {
				top = i - 1;
			}
		}
		return ret;
	}
}