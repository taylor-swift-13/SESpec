import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class MaxProduct {

    //@ requires args != null;
    //@ requires 1 <= Array && Array <= args.length;
    //@ assignable \nothing;
    //@ ensures (\forall int t; 0 <= t && t < Array; \result >= args[t]);
    //@ ensures Array == 1 ==> \result == args[0];
	/*@ spec_public @*/ public static int maxProduct(int[] args, int Array) {
		int[] mpis = new int[Array];
		//@ maintaining 0 <= array && array <= Array;
		//@ maintaining mpis.length == Array;
		//@ maintaining (\forall int t; 0 <= t && t < array; mpis[t] == args[t]);
		//@ decreases Array - array;
		for (int array = 0; array < Array; array++) {
			mpis[array] = args[array];
		}
		//@ maintaining 1 <= i && i <= Array;
		//@ maintaining mpis.length == Array;
		//@ maintaining (\forall int t; 0 <= t && t < i; mpis[t] >= args[t]);
		//@ maintaining (\forall int t; i <= t && t < Array; mpis[t] == args[t]);
		//@ decreases Array - i;
		for (int i = 1; i < Array; i++) {
			//@ maintaining 0 <= k && k <= i;
			//@ maintaining mpis.length == Array;
			//@ maintaining mpis[i] >= args[i];
			//@ maintaining (\forall int r; 0 <= r && r < k && args[i] > args[r]; mpis[i] >= mpis[r] * args[i]);
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
		//@ maintaining (\forall int t; 0 <= t && t < i; num >= mpis[t]);
		//@ maintaining num == (\max int t; 0 <= t && t < i; mpis[t]);
		//@ decreases Array - i;
		for (int i = 1; i < Array; i++) {
			if (mpis[i] > num) {
				num = mpis[i];
			}
		}
		return num;
	}
}