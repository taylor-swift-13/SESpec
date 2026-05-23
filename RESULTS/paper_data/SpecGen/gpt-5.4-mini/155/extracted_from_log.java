import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class MaxProduct {

	//@ requires args != null;
	//@ requires Array > 0;
	//@ requires Array <= args.length;
 
	//@ ensures (\forall int i; 0 < i && i < Array; \result >= args[i]);  
	public static int maxProduct(int[] args, int Array) {
		int[] mpis = new int[Array];
		//@ maintaining 0 <= array && array <= Array;
		//@ maintaining (\forall int j; 0 <= j && j < array; mpis[j] == args[j]);
		//@ decreases Array - array;
		for (int array = 0; array < Array; array++) {
			mpis[array] = args[array];
		}
		//@ maintaining 1 <= i && i <= Array;
		//@ maintaining (\forall int j; 0 < j && j < i; mpis[j] >= args[j]);  
		//@ decreases Array - i;
		for (int i = 1; i < Array; i++) {
			//@ maintaining 0 <= k && k <= i;
			//@ maintaining (\forall int j; 0 <= j && j < k; mpis[i] >= mpis[j] * args[i] || args[i] <= args[j]);
			//@ decreases i - k;
			for (int k = 0; k < i; k++) {
				if (args[i] > args[k]
						&& mpis[i] < (mpis[k] * args[i])) {
					mpis[i] = mpis[k] * args[i];
				}
			}
		}
		int num = mpis[0];
		//@ maintaining 1 <= i && i <= Array;
		//@ maintaining (\forall int j; 0 <= j && j < i; num >= mpis[j]);
		//@ decreases Array - i;
		for (int i = 1; i < Array; i++) {
			if (mpis[i] > num) {
				num = mpis[i];
			}
		}
		return num;
	}
}