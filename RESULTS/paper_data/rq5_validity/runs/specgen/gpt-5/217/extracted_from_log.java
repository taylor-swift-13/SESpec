import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class Last {

    //@ requires args != null;
    //@ requires 0 <= y && y <= args.length;
    //@ requires (\forall int i; 0 <= i && i + 1 < y; args[i] <= args[i + 1]);
    //@ ensures (\forall int t; 0 <= t && t < args.length; args[t] == \old(args[t]));
    //@ ensures (\result == -1) ==> (\forall int j; 0 <= j && j < y; args[j] != x);
    //@ ensures (\result != -1) ==> (0 <= \result && \result < y && args[\result] == x && (\forall int j; \result < j && j < y; args[j] != x));
    //@ ensures (\exists int j; 0 <= j && j < y; args[j] == x) ==> (\result != -1 && (\forall int j; 0 <= j && j < y && args[j] == x ==> j <= \result));
	public static int last(int[] args, int x, int y) {
		int i = 0;
		int r = y - 1;
		int k = -1;

        //@ maintaining 0 <= i && i <= y;
        //@ maintaining -1 <= r && r < y;
        //@ maintaining i <= r + 1;
        //@ maintaining (\forall int j; 0 <= j && j < i; args[j] <= x);
        //@ maintaining (\forall int j; r < j && j < y; args[j] > x);
        //@ maintaining (k == -1 || (0 <= k && k < i && args[k] == x));
        //@ maintaining (\forall int j; 0 <= j && j < i && args[j] == x ==> j <= k);
        //@ decreases r - i + 1;
		while (i <= r) {
			int tmp = (i + r) / 2;
			if (args[tmp] == x) {
				k = tmp;
				i = tmp + 1;
			} else if (args[tmp] < x) {
				i = tmp + 1;
			} else {
				r = tmp - 1;
			}
		}

		return k;
	}
}