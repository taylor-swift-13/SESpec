import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class CountFac {

	//@ requires number >= 1;
	//@ ensures number == 1 ==> \result == 1;
	//@ ensures number > 1 ==> \result >= 0;
	public static int countFac(int number) {
		int result = 0;
		if (number == 1)
			return 1;
		//@ maintaining 2 <= c && c - 1 <= number / c + 1;  
		//@ maintaining result >= 0;
 
		//@ decreases number - c;
		for (int c = 2; c <= number / c; c++) {
			if (number % c == 0) {
				result++;
				if (number / c == c) {
					break;
				}
			}
		}
		return result;
	}
}