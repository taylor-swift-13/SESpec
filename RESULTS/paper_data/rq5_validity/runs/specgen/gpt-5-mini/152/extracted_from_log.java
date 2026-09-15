import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class GetNumber {
	/*@ 
	  @ requires number >= 0;
	  @ 
	  @ // If p denotes a 1-based position in the sequence "all odd numbers from 1..number (increasing) followed by all even numbers from 1..number (increasing)",
	  @ // then the result is the p-th element of that sequence.
	  @ ensures 1 <= p && p <= number && p <= (number + 1) / 2 ==> \result == 2 * p - 1;
	  @ ensures 1 <= p && p <= number && p >  (number + 1) / 2 ==> \result == 2 * (p - (number + 1) / 2);
	  @ ensures !(1 <= p && p <= number) ==> \result == 0;
	  @*/
	public static int getNumber(int number, int p) {
		int result[] = new int[number];
		int b[] = new int[number];
		int c, j = 0;
		/*@ 
		  @ // build result: result[c] = c+1 for c in 0..number-1
		  @ maintaining 0 <= c && c <= number;
		  @ maintaining (\forall int i; 0 <= i && i < c; result[i] == i + 1);
		  @ decreases number - c;
		  @*/
		for (c = 0; c < number; c++) {
			result[c] = c + 1;
		}
		/*@
		  @ // scan for odd numbers, counting them in j; b[0..c-1] equals result[0..c-1]
		  @ maintaining 0 <= c && c <= number;
		  @ maintaining 0 <= j && j <= number;
		  @ maintaining (\forall int i; 0 <= i && i < c; b[i] == result[i]);
 
		  @ decreases number - c;
		  @*/
		for (c = 0; c < number; c++) {
			b[c] = result[c];
			if (result[c] % 2 != 0) {
				j++;
				if (j == p) {
					return result[c];
				}
			}
		}
		/*@
		  @ // after the odd-scan, j equals the total number of odd entries in result[0..number-1].
		  @ // Now scan evens; maintain b[0..c-1]==result[0..c-1] and that j equals
		  @ // (number of odds) + (number of evens seen so far in this loop).
 
 
 
 
		  @                      (\sum int x; 0 <= x && x < c; (result[x] % 2 == 0 ? 1 : 0));
		  @ decreases number - c;
		  @*/
		for (c = 0; c < number; c++) {
			b[c] = result[c];
			if (result[c] % 2 == 0) {
				j++;
				if (j == p) {
					return result[c];
				}
			}
		}
		return 0;
	}
}