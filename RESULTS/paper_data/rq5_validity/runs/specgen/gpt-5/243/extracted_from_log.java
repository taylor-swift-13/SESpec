import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class GetPairsCount {

	/*@
	  @ requires pairs != null;
	  @ requires 0 <= num && num <= pairs.length;
	  @ ensures \result ==
	  @   (\sum int i; 0 <= i && i < num;
	  @       (\sum int j; i + 1 <= j && j < num;
	  @           (pairs[i] + pairs[j] == p ? 1 : 0)));
	  @ ensures 0 <= \result && \result <= (num * (num - 1)) / 2;
	  @*/
	public static int getPairsCount(int[] pairs, int num, int p) {
		int result = 0;
		//@ maintaining 0 <= index && index <= num;
		//@ maintaining result == (\sum int i; 0 <= i && i < index; (\sum int jj; i + 1 <= jj && jj < num; (pairs[i] + pairs[jj] == p ? 1 : 0)));
		//@ decreases num - index;
		for (int index = 0; index < num; index++) {
			//@ ghost int resBase = result;
			//@ maintaining index + 1 <= j && j <= num;
			//@ maintaining result == resBase + (\sum int t; index + 1 <= t && t < j; (pairs[index] + pairs[t] == p ? 1 : 0));
			//@ decreases num - j;
			for (int j = index + 1; j < num; j++) {
				if (pairs[index] + pairs[j] == p) {
					result++;
				}
			}
		}
		return result;
	}
}