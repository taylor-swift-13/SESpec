import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class MaxPrimeFactors {

	/*@ 
	  @ requires num >= 0;
	  @ 
	  @ // If the original number is 0 or 1 there are no prime factors.
	  @ ensures \old(num) <= 1 ==> \result == 0;
	  @ 
	  @ // Otherwise the result is a prime divisor of the original number and is
	  @ // greater than or equal to any other prime divisor of the original number.
	  @ ensures \old(num) > 1 ==>
	  @   (\result > 1
	  @    && (\old(num) % \result) == 0
	  @    && (\forall int d; 2 <= d && d < \result; \result % d != 0)
	  @    && (\forall int p; 2 <= p && p <= \old(num) && (\old(num) % p) == 0
	  @         && (\forall int q; 2 <= q && q < p; p % q != 0) ==> p <= \result));
	  @*/
	public static int maxPrimeFactors(int num) {
		int result = 0;
		/*@ ghost int orig = num; @*/
		/*@ 
 
		  @ maintaining result >= 0 && result <= (orig >= 0 ? orig : 0);
		  @ // The current num is always a divisor of the original number while positive.
		  @ maintaining num > 0 ==> (orig % num) == 0;
		  @ decreases (orig > 2 ? orig + 2 + 1 : 0) + (c + 2);  
		  @*/
		for (int c = 2; c <= num; c++) {
			/*@ 
			  @ // Inner loop: as long as c divides the current num we extract that prime factor.
 
 
			  @ maintaining num >= 0;
			  @ maintaining num > 0 ==> (orig % num) == 0;
 
			  @*/
			while (num % c == 0) {
				result = c;
				num /= c;
			}
		}
		return result;
	}
}