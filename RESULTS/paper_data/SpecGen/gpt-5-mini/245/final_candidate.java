import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class GetPairsCount {

    /*@ public normal_behavior
      @   requires pairs != null;
      @   requires 0 <= num && num <= pairs.length;
 
 
      @   ensures (\forall int k; 0 <= k && k < pairs.length; pairs[k] == \old(pairs[k]));
      @*/
	public static int getPairsCount(int[] pairs, int num, int p) {
		int ret = 0;
            //@ maintaining 0 <= index && index <= num;
 
            //@ decreases num - index;
		for (int index = 0; index < num; index++) {
                //@ maintaining index+1 <= j && j <= num;
                //@ maintaining ret == (\sum int ii; 0 < ii && ii < index; (\sum int jj; ii+1 <= jj && jj <= num; (pairs[ii] - pairs[jj] == p ? 1 : 0)))  
                //@          + (\sum int jj; index+1 <= jj && jj < j; (pairs[index] + pairs[jj] == p ? 1 : 0));
                //@ decreases num - j;
			for (int j = index + 1; j < num; j++) {
				if (pairs[index] + pairs[j] == p) {
					ret++;
				}
			}
		}
		return ret;
	}
}
