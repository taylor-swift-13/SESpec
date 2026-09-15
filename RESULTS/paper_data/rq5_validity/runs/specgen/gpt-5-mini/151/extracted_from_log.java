import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class GetNumber {

	/*@ 
	  @ requires number >= 0;
	  @ requires p >= 0;
	  @ 
	  @ // If p is outside 1..number then method returns 0 (nothing found).
 
	  @ 
	  @ // Otherwise result is the p-th element of the sequence that lists all odd numbers
	  @ // in 1..number (in increasing order) followed by all even numbers in 1..number
	  @ // (in increasing order). Let numOdds = (number+1)/2.
 
	  @           (\result == (p <= (number + 1) / 2 
	  @                         ? 2*(p-1) + 1 
	  @                         : 2*(p - (number + 1) / 2)));
	  @*/
	public static int getNumber(int number, int p) {
		int result[] = new int[number];
		int b[] = new int[number];
		int c, ii = 0;
		/*@ 
		  @ // initialize result: after c iterations result[0..c-1] == 1..c
		  @ maintaining 0 <= c && c <= number;
		  @ maintaining (\forall int j; 0 <= j && j < c; result[j] == j + 1);
		  @ decreases number - c;
		  @*/
		for (c = 0; c < number; c++) {
			result[c] = c + 1;
		}
		/*@ 
		  @ // copy and count odds: after c iterations b[0..c-1] == result[0..c-1]
		  @ // and ii is between 0 and number (it counts odds seen so far).
		  @ maintaining 0 <= c && c <= number;
		  @ maintaining (\forall int j; 0 <= j && j < c; b[j] == result[j]);
		  @ maintaining 0 <= ii && ii <= number;
		  @ decreases number - c;
		  @*/
		for (c = 0; c < number; c++) {
			b[c] = result[c];
			if (result[c] % 2 != 0) {
				ii++;
				if (ii == p) {
					return result[c];
				}
			}
		}
		/*@ 
		  @ // copy and count evens: after c iterations b[0..c-1] == result[0..c-1]
		  @ // and ii is between 0 and number (it counts odds + evens seen so far).
		  @ maintaining 0 <= c && c <= number;
		  @ maintaining (\forall int j; 0 <= j && j < c; b[j] == result[j]);
		  @ maintaining 0 <= ii && ii <= number;
		  @ decreases number - c;
		  @*/
		for (c = 0; c < number; c++) {
			b[c] = result[c];
			if (result[c] % 2 == 0) {
				ii++;
				if (ii == p) {
					return result[c];
				}
			}
		}
		return 0;
	}
}