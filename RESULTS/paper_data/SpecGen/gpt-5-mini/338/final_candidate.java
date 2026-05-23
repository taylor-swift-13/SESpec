import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class MaxPrimeFactors {

	/*@ 
	  @ requires num >= 2;
	  @ ensures (\old(num) <= 1) ==> \result == 0;
 
	  @   (\result >= 2
	  @    && \old(num) % \result == 0
	  @    && (\forall int q;
	  @          2 <= q && q <= \old(num)
	  @          && (\forall int d; 2 <= d && d < q ==> q % d != 0)  // q is prime
	  @          && \old(num) % q == 0
	  @          ==> q <= \result));
	  @ ensures (\result >= 2) ==> (\forall int d; 2 <= d && d < \result ==> \result % d != 0); // result is prime
	  @*/
	public static int maxPrimeFactors(int num) {
		int result = 0;
		//@ ghost int N0 = num; // original value of num for loop invariants
		/*@ 
		  @ // Invariant for outer loop: any prime divisor < j of the original number N0 is <= result.
		  @ maintaining 2 <= j && 0 <= result && N0 >= 2;
		  @ // num is always positive (so modulo by num is defined)
		  @ maintaining num >= 1;
		  @ maintaining N0 % num == 0;
		  @ maintaining (\forall int p;
		  @                2 <= p && p < j
		  @                && (\forall int d; 2 <= d && d < p ==> p % d != 0)  // p is prime
		  @                && N0 % p == 0
		  @                ==> p <= result);
		  @ decreases N0 - j;
		  @*/
		for (int j = 2; j <= num; j++) {
			/*@
			  @ // Invariant for inner loop: N0 is divisible by current num; j is fixed; result is at most j.
			  @ maintaining j >= 2 && 0 <= result && N0 >= 2;
			  @ // num is always positive (so modulo by num is defined)
			  @ maintaining num >= 1;
			  @ maintaining N0 % num == 0;
			  @ maintaining (\forall int p;
			  @                2 <= p && p < j
			  @                && (\forall int d; 2 <= d && d < p ==> p % d != 0)
			  @                && N0 % p == 0
			  @                ==> p <= result);
			  @ decreases num;
			  @*/
			while (num % j == 0) {
				result = j;
				num /= j;
			}
		}
		return result;
	}
}
