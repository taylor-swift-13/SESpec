import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class GetGcd {

	/*@ requires arg != null;
	  @ requires arg.length > 0;
	  @ 
	  @ // If the array is non-increasing (no later element greater than an earlier one),
	  @ // the method never updates g and returns 0.
 
	  @ 
	  @ // Otherwise the result is the maximum among those elements arg[i] for which
	  @ // there exists a later element strictly greater than arg[i].
	  @ ensures (\result != 0) ==>
	  @           (\exists int i; 0 <= i && i < arg.length &&
	  @               (\exists int j; i < j && j < arg.length && arg[j] > arg[i]) &&
	  @               \result == arg[i]);
 
	  @           (\forall int i; 0 <= i && i < arg.length &&
	  @               (\exists int j; i < j && j < arg.length && arg[j] > arg[i]) ==> arg[i] <= \result);
	  @ 
	  @ ensures 0 <= \result;
	  @*/
	public static int getGcd(int[] arg) {
		int g = 0;
		int ret = arg[0];
		/*@ 
		  @ maintaining 1 <= j && j <= arg.length;
		  @ maintaining (\forall int k; 0 <= k && k < j; ret <= arg[k]) 
		  @           && (\exists int k; 0 <= k && k < j; ret == arg[k]);
		  @ maintaining (g == 0) || (\exists int m; 0 <= m && m < j && g == arg[m]);
		  @ maintaining (\exists int m; 0 < m && m < j &&  
		  @                  (\exists int t; m < t && t < j && arg[t] > arg[m]) ==> arg[m] <= g);
		  @ maintaining (g == 0) || (\exists int m; 0 <= m && m < j &&
		  @                  (\exists int t; m < t && t < j && arg[t] > arg[m]) && g == arg[m]);
		  @ decreases arg.length - j;
		  @*/
		for (int j = 1; j < arg.length; j++) {
			if (arg[j] > ret) {
				g = g > ret ? g : ret;
			} else {
				ret = arg[j];
			}
		}
		return g;
	}
}