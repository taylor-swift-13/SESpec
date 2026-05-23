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
			//@ maintaining index + 1 <= c && c <= num;
			//@ maintaining ret == (\sum int i, j; 0 < i && i <= index && i <= j && j <= num; (args[i] >= args[j] ? 1 : 0))  
			//@                   + (\sum int j; index < j && j < c; (args[index] > args[j] ? 1 : 0));
			//@ decreases num - c;
			for (int c = index + 1; c < num; c++) {
				if (args[index] > args[c]) {
					ret++;
				}
			}
		}
		return ret;
	}
}