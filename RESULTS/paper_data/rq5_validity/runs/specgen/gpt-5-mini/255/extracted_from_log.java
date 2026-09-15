import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class LeftInsertion {

	//@ requires args != null;
	//@ requires (\forall int i,j; 0 <= i && i < j && j < args.length; args[i] <= args[j]); // array must be non-decreasingly sorted
	//@ ensures 0 <= \result && \result <= args.length;
	//@ ensures (\exists int i; 0 <= i && i < args.length; args[i] == array) ==> (0 <= \result && \result < args.length && args[\result] == array);
	//@ ensures (\forall int i; 0 <= i && i < args.length; args[i] != array) ==>
	//@           ((\forall int j; 0 <= j && j < \result; args[j] < array) && (\forall int j; \result <= j && j < args.length; args[j] > array));
	public static int leftInsertion(int[] args, int array) {
		int result = 0;
		int top = args.length - 1;
		//@ maintaining 0 <= result && result <= args.length;
		//@ maintaining -1 <= top && top < args.length;
		//@ maintaining (\forall int j; 0 <= j && j < result; args[j] < array);
		//@ maintaining (\forall int j; top < j && j < args.length; args[j] >= array);
		//@ decreases top - result + 1;
		while (result <= top) {
			int i = (result + top) / 2;
			if (args[i] == array) {
				return i;
			} else if (args[i] < array) {
				result = i + 1;
			} else {
				top = i - 1;
			}
		}
		return result;
	}
}