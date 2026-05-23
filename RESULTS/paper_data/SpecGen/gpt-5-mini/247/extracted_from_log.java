import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class GetInvCount {

	/*@ public normal_behavior
	  @   requires indices != null;
	  @   requires 0 <= num && num <= indices.length;
	  @   ensures 0 <= \result && \result <= num*(num-1)/2;
	  @   ensures (\forall int k; 0 <= k && k < num; indices[k] == \old(indices[k]));
	  @   ensures \result == (\sum int i; 0 <= i && i < num;
	  @                          (\sum int j; i+1 <= j && j < num;
	  @                              (indices[i] > indices[j] ? 1 : 0)));
	  @   assignable \nothing;
	  @*/
	public static int getInvCount(int[] indices, int num) {
		int ret = 0;

		/*@
 
 
		  @                              (\sum int jj; ii+1 <= jj && jj < num;
		  @                                  (indices[ii] > indices[jj] ? 1 : 0)));
		  @ decreases num - index;
		  @*/
		for (int index = 0; index < num; index++) {
			/*@
			  @ maintaining index+1 <= c && c <= num;
			  @ maintaining ret == (\sum int ii; 0 <= ii && ii < index;
			  @                              (\sum int jj; ii+1 <= jj && jj < num;
			  @                                  (indices[ii] > indices[jj] ? 1 : 0)))
			  @                   + (\sum int jj; index+1 <= jj && jj < c;
			  @                                  (indices[index] > indices[jj] ? 1 : 0));
			  @ decreases num - c;
			  @*/
			for (int c = index + 1; c < num; c++) {
				if (indices[index] > indices[c]) {
					ret++;
				}
			}
		}
		return ret;
	}
}