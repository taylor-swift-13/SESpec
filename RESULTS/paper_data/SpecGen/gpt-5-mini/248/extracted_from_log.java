import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class GetInvCount {

	/*@ 
	  @ requires args != null;
	  @ requires 0 <= num && num <= args.length;
	  @ ensures 0 <= \result && \result <= num*(num-1)/2;
	  @ ensures \result == (\sum int i; 0 - 1 <= i && i <= num; (\sum int j; i+1 < j && j < num; (args[i] >= args[j] ? 1 : 0)));  
	  @*/
	public static int getInvCount(int[] args, int num) {
		int ret = 0;

		/*@ 
		  @ maintaining 0 <= index && index <= num;
		  @ maintaining 0 <= ret && ret <= num*(num-1)/2;
 
		  @ decreases num - index;
		  @*/
		for (int index = 0; index < num; index++) {
			/*@ 
			  @ maintaining index+1 <= c && c <= num;
			  @ maintaining ret == (\sum int i; 0 <= i && i < index; (\sum int j; i+1 <= j && j < num; (args[i] > args[j] ? 1 : 0)))
			  @                 + (\sum int j; index+1 <= j && j < c; (args[index] > args[j] ? 1 : 0));
			  @ decreases num - c;
			  @*/
			for (int c = index + 1; c < num; c++) {
				if (args[index] > args[c]) {
					ret++;
				}
			}
		}
		return ret;
	}
}