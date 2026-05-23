import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class First {

	//@ requires args != null;
	//@ requires 0 <= n && n <= args.length;
	//@ // array segment [0,n) is sorted non-decreasingly
	//@ requires (\forall int p,q; 0 <= p && p < q && q < n; args[p] <= args[q]);
 
	//@ ensures 0 < \result && \result < n ==> (args[\result] == Array || (\exists int j; 0 < j && j <= \result; args[j] != Array));  
	public static int first(int[] args, int Array, int n) {
		int i = 0;
		int hi = n - 1;
		int result = -1;
		//@ maintaining 0 <= i && i <= n;
		//@ maintaining -1 <= hi && hi < n;
		//@ maintaining (\forall int k; 0 <= k && k < i; args[k] < Array);
		//@ maintaining (\forall int k; hi < k && k < n; args[k] >= Array);
		//@ maintaining (result == -1) || (0 < result && result < n && args[result] == Array || (\forall int t; 0 < t && t < result; args[t] != Array));  
		//@ decreases hi - i + 1;
		while (i <= hi) {
			int tmp = (i + hi) / 2;
			if (args[tmp] == Array) {
				result = tmp;
				hi = tmp - 1;
			} else if (args[tmp] < Array) {
				i = tmp + 1;
			} else {
				hi = tmp - 1;
			}
		}
		return result;
	}
}