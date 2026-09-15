import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class MaxProduct {

    /*@ spec_public @*/
    //@ requires args != null && 1 <= Array && Array <= args.length;
    //@ ensures (\forall int i; 0 <= i && i < Array; \result >= args[i]);
    //@ ensures Array == 1 ==> \result == args[0];
	public static int maxProduct(int[] args, int Array) {
		int[] mpis = new int[Array];
        //@ maintaining 0 <= array && array <= Array;
        //@ maintaining (\forall int k; 0 <= k && k < array; mpis[k] == args[k]);
        //@ decreases Array - array;
		for (int array = 0; array < Array; array++) {
			mpis[array] = args[array];
		}
        //@ maintaining 1 <= i && i <= Array;
        //@ maintaining (\forall int t; 0 <= t && t < i; mpis[t] >= args[t]);
        //@ decreases Array - i;
		for (int i = 1; i < Array; i++) {
            //@ maintaining 0 <= p && p <= i;
            //@ maintaining mpis[i] >= args[i];
            //@ maintaining (\forall int t; 0 <= t && t < p; args[i] > args[t] ==> mpis[i] >= mpis[t] * args[i]);
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
        //@ maintaining (\forall int j; 0 <= j && j < i; result >= mpis[j]);
        //@ maintaining (\exists int j; 0 <= j && j < i; result == mpis[j]);
        //@ decreases Array - i;
		for (int i = 1; i < Array; i++) {
			if (mpis[i] > result) {
				result = mpis[i];
			}
		}
		return result;
	}
}