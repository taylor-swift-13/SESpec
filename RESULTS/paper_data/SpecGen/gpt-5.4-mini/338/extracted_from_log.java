import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class MaxPrimeFactors {

	//@ requires num >= 0;
	//@ ensures \result >= 0;
 
	//@ ensures (\result > 1) ==> (\forall int d; 2 <= d && d <= \result / 2; \result % d != 0);
	//@ ensures (\result > 0 && num > 1) ==> num % \result == 0;
	public static int maxPrimeFactors(int num) {
		int result = 0;
		//@ maintaining 0 <= result;
 
		//@ maintaining (\forall int d; 2 <= d && d < j; num % d != 0 || d <= result);
		//@ decreases num - j + 1;
		for (int j = 2; j <= num; j++) {
			//@ maintaining num >= 0;
			//@ maintaining 0 <= result;
			//@ maintaining num >= 0;
			//@ decreases num;
			while (num % j == 0) {
				result = j;
				num /= j;
			}
		}
		return result;
	}
}