import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class MaxPrimeFactors {

	//@ requires num >= 0;
	//@ ensures \result >= 0;
	//@ ensures num <= 1 ==> \result == 0;
	//@ ensures num > 1 ==> (\result == 0 || (\result > 1 && num % \result == 0));
	public static int maxPrimeFactors(int num) {
		int result = 0;
		//@ maintaining 0 < c && c - 1 <= num + 1;  
		//@ maintaining result >= 0;
		//@ maintaining result == 0 || (\exists int d; 2 <= d && d <= c; result == d && num % d == 0);
		//@ decreases num - c + 1;
		for (int c = 2; c <= num; c++) {
			//@ maintaining 2 <= c && c <= num + 1;
			//@ maintaining result >= 0;
			//@ maintaining result == 0 || (result > 1 && (\forall int d; 2 <= d && d < c; d == result || num % d != 0));
			//@ decreases num - c + 1;
			while (num % c == 0) {
				result = c;
				num /= c;
			}
		}
		return result;
	}
}