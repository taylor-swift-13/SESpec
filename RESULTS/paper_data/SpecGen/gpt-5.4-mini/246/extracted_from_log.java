import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class GetInvCount {

	//@ requires args != null;
	//@ requires 0 <= num && num <= args.length;
	//@ ensures \result >= 0;
 
	public static int getInvCount(int[] args, int num) {
		int ret = 0;

		//@ maintaining 0 <= index && index <= num;
		//@ maintaining 0 <= ret;
 
		//@ decreases num - index;
		for (int index = 0; index < num; index++) {
			//@ maintaining index + 1 <= k && k <= num;
			//@ maintaining ret == (\sum int i; 0 < i && i < index; (\num_of int j; i < j && j <= num; args[i] > args[j])) + (\num_of int j; index <= j && j <= k; args[index] > args[j]);  
			//@ decreases num - k;
			for (int k = index + 1; k < num; k++) {
				if (args[index] > args[k]) {
					ret++;
				}
			}
		}
		return ret;
	}
}