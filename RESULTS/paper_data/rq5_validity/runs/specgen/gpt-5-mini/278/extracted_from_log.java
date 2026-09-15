import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class GetGcd {

	//@ requires args != null && args.length >= 1;
	//@ ensures (\result == 0) || (\exists int i; 0 <= i && i < args.length; args[i] == \result);
 
	public static int getGcd(int[] args) {
		int ret = 0;
		int tmp = args[0];
		//@ maintaining 1 <= j && j <= args.length;
		//@ maintaining (\forall int i; 0 <= i && i < j; tmp <= args[i]) && (\exists int i; 0 <= i && i < j; tmp == args[i]);
		//@ maintaining (ret == 0) || (\exists int p; 0 <= p && p < j; args[p] == ret);
		//@ decreases args.length - j;
		for (int j = 1; j < args.length; j++) {
			if (args[j] > tmp) {
				ret = ret > tmp ? ret : tmp;
			} else {
				tmp = args[j];
			}
		}
		return ret;
	}
}