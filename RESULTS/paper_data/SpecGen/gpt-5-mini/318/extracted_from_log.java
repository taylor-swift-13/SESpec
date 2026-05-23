import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class CountFac {

	/*@ 
	  @ requires num >= 1;
	  @ 
	  @ // If num == 1 the method returns 1 (as in the original code).
	  @ ensures num == 1 ==> \result == 1;
	  @ 
	  @ // For num > 1 the result is the number of divisors d with 2 <= d <= floor(sqrt(num)) that divide num.
 
	  @*/
	public static int countFac(int num) {
		int result = 0;
		if (num == 1)
			return 1;
		//@ maintaining result >= 0;
		//@ maintaining 2 <= c;
 
		//@ decreases num - c + 1;
		for (int c = 2; c <= num / c; c++) {
			if (num % c == 0) {
				result++;
				if (num / c == c) {
					break;
				}
			}
		}
		return result;
	}
}