import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class MaxPrimeFactors {

	//@ requires num >= 0;
	//@ ensures \result >= 0;
 
	//@ ensures \result > 0 ==> (num % \result == 0);
	//@ ensures \result > 0 ==> (\forall int d; 2 <= d && d <= num; (num % d == 0) ==> d <= \result);
	public static int maxPrimeFactors(int num) {
		int ret = 0;
		//@ maintaining 2 <= j && j - 1 <= num + 1;  
		//@ maintaining ret >= 0;
		//@ maintaining ret == 0 || (\forall int d; 2 < d && d <= j; num % d == 0);  
 
		for (int j = 2; j <= num; j++) {
			//@ maintaining num >= 0;
			//@ maintaining ret >= 0;
			//@ maintaining 2 <= j && j <= num + 1;
			//@ decreases num;
			while (num % j == 0) {
				ret = j;
				num /= j;
			}
		}
		return ret;
	}
}