import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class First {

	//@ requires args != null;
	//@ requires n >= 0 && n <= args.length;
	//@ requires (\forall int p, q; 0 <= p && p < q && q < n; args[p] <= args[q]);
 
	//@ ensures (\result != -1) ==> (0 <= \result && \result < n && args[\result] == array);
 
	public static int first(int[] args, int array, int n) {
		int i = 0;
		int hi = n - 1;
		int result = -1;
		//@ maintaining 0 <= i && -1 <= hi && hi < n;
		//@ maintaining -1 <= result && result < n;
		//@ maintaining (\forall int t; 0 <= t && t < i; args[t] < array);
		//@ maintaining (\forall int t; hi < t && t < n; args[t] >= array);  
		//@ maintaining (result != -1) ==> (0 <= result && result < n && args[result] == array);
		//@ decreases hi - i + 1;
		while (i <= hi) {
			int tmp = (i + hi) / 2;
			if (args[tmp] == array) {
				result = tmp;
				hi = tmp - 1;
			} else if (args[tmp] < array) {
				i = tmp + 1;
			} else {
				hi = tmp - 1;
			}
		}
		return result;
	}
}