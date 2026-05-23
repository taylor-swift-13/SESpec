import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class First {

	/*@ 
	  @ requires args != null;
	  @ requires 0 <= n && n <= args.length;
	  @ /*@ spec_public @*/ 
	  @ // array sorted non-decreasing on the prefix of length n
	  @ requires (\forall int p, q; 0 <= p && p < q && q < n; args[p] <= args[q]);
	  @ ensures -1 <= \result && \result < n;
	  @ ensures \result == -1 <==> (\forall int i; 0 <= i && i < n; args[i] != array);
	  @ ensures 0 <= \result && \result < n ==> args[\result] == array 
	  @    && (\forall int j; 0 <= j && j < \result; args[j] != array);
	  @*/
	public static int first(int[] args, int array, int n) {
		int i = 0;
		int hi = n - 1;
		int result = -1;
		/*@ 
		  @ maintaining 0 <= i && i <= n;
		  @ maintaining -1 <= hi && hi < n;
		  @ maintaining -1 <= result && result < n;
		  @ maintaining (result != -1) ==> args[result] == array;
		  @ // all indices strictly less than i are strictly less than target
		  @ maintaining (\forall int j; 0 <= j && j < i; args[j] < array);
		  @ // all indices strictly greater than hi are greater or equal to target
		  @ maintaining (\forall int j; hi < j && j < n; args[j] >= array);
		  @ decreases hi - i + 1;
		  @*/
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