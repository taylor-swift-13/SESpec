import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class LeftInsertion {

	//@ requires args != null;
	//@ requires (\forall int p,q; 0 <= p && p < q && q < args.length ==> args[p] <= args[q]);
	//@ ensures 0 <= \result && \result <= args.length;
	//@ ensures (\result < args.length && args[\result] == Array) 
	//@          || ((\forall int j; 0 <= j && j < \result; args[j] < Array)
	//@              && (\forall int j; \result <= j && j < args.length; args[j] >= Array));
	public static int leftInsertion(int[] args, int Array) {
		int ret = 0;
		int top = args.length - 1;
		//@ maintaining 0 <= ret && ret <= args.length;
		//@ maintaining -1 <= top && top < args.length;
		//@ maintaining ret <= top + 1;
		//@ maintaining (\forall int j; 0 <= j && j < ret; args[j] < Array);
		//@ maintaining (\forall int j; top < j && j < args.length; args[j] >= Array);
		//@ decreases top - ret + 1;
		while (ret <= top) {
			int i = (ret + top) / 2;
			if (args[i] == Array) {
				return i;
			} else if (args[i] < Array) {
				ret = i + 1;
			} else {
				top = i - 1;
			}
		}
		return ret;
	}
}