import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class LeftInsertion {

	//@ requires args != null && args.length > 0;
	//@ requires \forall int j; 0 <= j && j < args.length; \forall int i; 0 <= i && i < j; args[i] <= args[j];
	//@ ensures (\exists int i; 0 <= i && i < args.length; args[i] == Array) ==> args[\result] == Array;
	//@ ensures (\forall int i; 0 <= i && i < args.length; args[i] != Array) ==> (\forall int j; 0 <= j && j < \result; args[j] < Array) && (\forall int k; \result <= k && k < args.length; args[k] >= Array);
	public static int leftInsertion(int[] args, int Array) {
		int ret = 0;
		int top = args.length - 1;
		//@ maintaining 0 <= ret && ret <= top + 1 && top < args.length;
		//@ maintaining (\forall int j; 0 <= j && j < ret; args[j] < Array);
		//@ maintaining (\forall int k; top + 1 <= k && k < args.length; args[k] >= Array);
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