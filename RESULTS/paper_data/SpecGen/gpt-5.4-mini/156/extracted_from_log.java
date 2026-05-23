import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class MaxProduct {

	//@ requires args != null;
	//@ requires Array >= 1 && Array <= args.length;
 
 
	public static int maxProduct(int[] args, int Array) {
		int[] mpis = new int[Array];
		//@ maintaining 0 <= array && array <= Array;
		//@ maintaining (\forall int i; 0 <= i && i < array; mpis[i] == args[i]);
		//@ decreases Array - array;
		for (int array = 0; array < Array; array++) {
			mpis[array] = args[array];
		}
		//@ maintaining 1 <= i && i <= Array;
 
		//@ decreases Array - i;
		for (int i = 1; i < Array; i++) {
			//@ maintaining 0 <= p && p <= i;
			//@ decreases i - p;
			for (int p = 0; p < i; p++) {
				if (args[i] > args[p]
						&& mpis[i] < (mpis[p] * args[i])) {
					mpis[i] = mpis[p] * args[i];
				}
			}
		}
		int num = mpis[0];
		//@ maintaining 1 <= i && i <= Array;
		//@ maintaining (\forall int k; 0 <= k && k < i; num >= mpis[k]);
		//@ decreases Array - i;
		for (int i = 1; i < Array; i++) {
			if (mpis[i] > num) {
				num = mpis[i];
			}
		}
		return num;
	}
}