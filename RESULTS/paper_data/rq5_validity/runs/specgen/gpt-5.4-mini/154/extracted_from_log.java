import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class MaxProduct {

	//@ requires args != null;
	//@ requires Array > 0 && Array <= args.length;
 
	//@                   (\max int j; 0 <= j && j <= i && (j == i || args[i] > args[j]); 
	//@                    (j == i ? args[i] : 1) ) );
	//@ ensures true;
	public static int maxProduct(int[] args, int Array) {
		int[] mpis = new int[Array];
		//@ maintaining 0 <= array && array <= Array;
		//@ maintaining (\forall int k; 0 <= k && k < array; mpis[k] == args[k]);
		//@ decreases Array - array;
		for (int array = 0; array < Array; array++) {
			mpis[array] = args[array];
		}
		//@ maintaining 1 <= i && i <= Array;
		//@ maintaining (\forall int k; 0 <= k && k < i; 
		//@              mpis[k] >= args[k]);
		//@ decreases Array - i;
		for (int i = 1; i < Array; i++) {
			//@ maintaining 0 <= p && p <= i;
			//@ maintaining (\forall int k; 0 <= k && k < p; 
			//@              mpis[i] >= mpis[k] * args[i]);
			//@ decreases i - p;
			for (int p = 0; p < i; p++) {
				if (args[i] > args[p]
						&& mpis[i] < (mpis[p] * args[i])) {
					mpis[i] = mpis[p] * args[i];
				}
			}
		}
		int result = mpis[0];
		//@ maintaining 1 <= i && i <= Array;
		//@ maintaining (\forall int k; 0 <= k && k < i; result >= mpis[k]);
		//@ decreases Array - i;
		for (int i = 1; i < Array; i++) {
			if (mpis[i] > result) {
				result = mpis[i];
			}
		}
		return result;
	}
}