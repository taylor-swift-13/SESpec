import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class Last {

	//@ requires args != null;
	//@ requires 0 <= y && y <= args.length;
	//@ requires (\forall int i, j; 0 <= i && i < j && j < y; args[i] <= args[j]);
	//@ ensures \result == -1 <==> (\forall int i; 0 <= i && i < y; args[i] != x);
	//@ ensures 0 <= \result && \result < y ==> args[\result] == x && (\forall int j; \result < j && j < y; args[j] != x);
	public static int last(int[] args, int x, int y) {
		int i = 0;
		int r = y - 1;
		int p = -1;

		/*@ 
		  @ maintaining 0 <= i && i <= y;
		  @ maintaining -1 <= r && r < y;
		  @ maintaining (\forall int k; 0 <= k && k < i; args[k] <= x);
		  @ maintaining (\forall int k; r < k && k < y; args[k] > x);
		  @ maintaining p < i;
		  @ maintaining -1 <= p;
		  @ maintaining p == -1 || (0 <= p && p < y && args[p] == x);
		  @ maintaining (\forall int k; p < k && k < i; args[k] != x);
		  @ decreases r - i + 1;
		  @*/
		while (i <= r) {
			int tmp = (i + r) / 2;
			if (args[tmp] == x) {
				p = tmp;
				i = tmp + 1;
			} else if (args[tmp] < x) {
				i = tmp + 1;
			} else {
				r = tmp - 1;
			}
		}

		return p;
	}
}