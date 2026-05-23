import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class GetInvCount {

    /*@ 
      @ requires args != null;
      @ requires 0 <= num && num <= args.length;
 
 
 
      @*/
	public static int getInvCount(int[] args, int num) {
		int ret = 0;

		/*@ 
		  @ maintaining 0 <= index && index <= num;
 
		  @ decreases num - index;
		  @*/
		for (int index = 0; index < num; index++) {
			/*@ 
			  @ maintaining index >= 0 && index < num;
			  @ maintaining index+1 <= k && k <= num;
			  @ maintaining ret == (\sum int i; 0 <= i && i <= index; (\sum int j; i < j && j < num && args[i] > args[j]; 1))  
			  @                    + (\sum int j; index < j && j < k && args[index] > args[j]; 1);
			  @ decreases num - k;
			  @*/
			for (int k = index + 1; k < num; k++) {
				if (args[index] > args[k]) {
					ret++;
				}
			}
		}
		return ret;
	}
}