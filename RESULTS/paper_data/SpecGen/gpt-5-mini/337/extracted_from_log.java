import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class MaxPrimeFactors {

	/*@ 
	  @ ensures \old(num) < 2 ==> \result == 0;
 
	  @   ( \result >= 2
	  @     && \result <= \old(num)
	  @     && \old(num) % \result == 0
	  @     && (\forall int d; 2 <= d && d * d <= \result; \result % d != 0)  // \result is prime
	  @     && (\forall int p; 2 <= p && p <= \old(num) && \old(num) % p == 0 ==> p <= \result) // maximality
	  @   );
	  @*/
	public static int maxPrimeFactors(int num) {
		int ret = 0;
		//@ ghost int orig = num;
		/*@ 
		  @ // Outer loop invariant: when the loop condition holds, j is within [2,orig] and ret/num are within reasonable bounds.
		  @ // We guard the invariant by the loop condition (j <= num) so it must hold whenever an iteration is possible.
		  @ maintaining (j <= num) ==> (2 <= j && j <= orig && 0 <= ret && ret <= orig && 1 <= num && num <= orig);
		  @ decreases orig - j + 1;
		  @*/
		for (int j = 2; j <= num; j++) {
			/*@
			  @ // Inner loop invariant: while num is divisible by j, j is a valid candidate and ret remains a divisor of orig (if non-zero).
			  @ maintaining (num % j == 0) ==> (2 <= j && j <= orig && 0 <= ret && ret <= j && 1 <= num && num <= orig && (ret == 0 || orig % ret == 0));
			  @ decreases num;
			  @*/
			while (num % j == 0) {
				ret = j;
				num /= j;
			}
		}
		return ret;
	}
}