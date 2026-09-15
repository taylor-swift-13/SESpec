import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class CountPairs {

	/*@ 
	  @ requires p != null;
	  @ // 'array' parameter is not used by the implementation; no constraint imposed on it
	  @ ensures 0 <= \result && \result <= (\old(p.length) * (\old(p.length) - 1)) / 2;
	  @ ensures \result == (\sum int i; 0 <= i && i < p.length - 1;
	  @                         \sum int j; i < j && j < p.length;
	  @                             (p[i] != p[j] ? 1 : 0));
	  @*/
	public static int countPairs(int[] p, int array) {
		int count = 0;
		int total = p.length;
		/*@ 
 
 
		  @ // count equals number of unequal pairs with first index < index
 
		  @                             \sum int j; i < j && j < total;
		  @                                 (p[i] != p[j] ? 1 : 0));
		  @ decreases total - index;
		  @*/
		for (int index = 0; index < total - 1; index++) {
			/*@
			  @ maintaining index + 1 <= c && c <= total;
			  @ // count equals previously counted pairs (with first index < index)
			  @ // plus the pairs (index, j) already processed by the inner loop (j in [index+1, c-1])
			  @ maintaining count == (\sum int i; 0 <= i && i < index;
			  @                             \sum int j; i < j && j < total;
			  @                                 (p[i] != p[j] ? 1 : 0))
			  @                      + (\sum int j; index+1 <= j && j < c;
			  @                             (p[index] != p[j] ? 1 : 0));
			  @ decreases total - c;
			  @*/
			for (int c = index + 1; c < total; c++) {
				if (p[index] != p[c]) {
					count++;
				}
			}
		}
		return count;
	}
}