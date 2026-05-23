import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindFixedPoint {

	/*@ 
	  @ requires args != null;
	  @ requires 0 <= array && array <= args.length;
	  @ // array segment [0,array) is strictly increasing, needed for binary-search correctness
	  @ requires (\forall int k; 0 < k && k < array; args[k-1] < args[k]);
	  @ 
	  @ ensures (\result == -1) <==> (\forall int k; 0 <= k && k < array; args[k] != k);
	  @ ensures 0 <= \result && \result < array ==> args[\result] == \result;
	  @*/
	public static int findFixedPoint(int[] args, int array) {
		int ret = 0;
		int stop = array - 1;
		/*@ 
		  @ maintaining 0 <= ret && ret <= array;
		  @ maintaining -1 <= stop && stop < array;
		  @ maintaining ret <= stop + 1;
		  @ // all indices < ret cannot be fixed points
		  @ maintaining (\forall int k; 0 <= k && k < ret; args[k] < k);
		  @ // all indices > stop cannot be fixed points
		  @ maintaining (\forall int k; stop < k && k < array; args[k] > k);
		  @ decreases stop - ret + 1;
		  @*/
		while (ret <= stop) {
			int i = ret + (stop - ret) / 2;
			if (args[i] == i) {
				return i;
			} else if (args[i] < i) {
				ret = i + 1;
			} else {
				stop = i - 1;
			}
		}
		return -1;
	}
}