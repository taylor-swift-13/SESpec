import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class LeftInsertion {

	//@ requires args != null;
	//@ requires (\forall int i, j; 0 <= i && i < j && j < args.length; args[i] <= args[j]);
 
	//@ ensures (\result >= 0 && \result <= args.length);
	//@ ensures (\forall int i; 0 < i && i < \result; args[i] <= array);  
	//@ ensures (\forall int i; \result <= i && i < args.length; args[i] > array) || (\exists int i; 0 <= i && i < args.length; args[i] == array);
	public static int leftInsertion(int[] args, int array) {
		int ret = 0;
		int top = args.length - 1;
		//@ maintaining 0 <= ret && ret <= args.length;
		//@ maintaining -1 <= top && top < args.length;
		//@ maintaining ret <= top + 1;
		//@ maintaining (\forall int i; 0 <= i && i < ret; args[i] < array);
		//@ maintaining (\forall int i; top < i && i < args.length; args[i] > array);
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