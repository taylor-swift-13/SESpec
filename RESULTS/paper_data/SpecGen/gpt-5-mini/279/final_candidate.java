import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class GetGcd {

	/*@ 
	  @ requires args != null;
	  @ requires args.length >= 1;
	  @ ensures \result >= 0;
	  @ ensures (\result == 0) || (\exists int i; 0 <= i && i < args.length; args[i] == \result);
	  @*/
	public static int getGcd(int[] args) {
		int g = 0;
		int ret = args[0];
		/*@ 
		  @ maintaining 1 <= j && j <= args.length;
		  @ maintaining (\exists int p; 0 <= p && p < j; ret == args[p]);
		  @ maintaining g == 0 || (\exists int q; 0 <= q && q < j; g == args[q]);
		  @ maintaining g >= 0;
		  @ decreases args.length - j;
		  @*/
		for (int j = 1; j < args.length; j++) {
			if (args[j] > ret) {
				g = g > ret ? g : ret;
			} else {
				ret = args[j];
			}
		}
		return g;
	}
}