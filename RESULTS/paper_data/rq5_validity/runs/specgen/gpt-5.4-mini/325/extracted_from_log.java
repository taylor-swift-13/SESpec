import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FirstDigit {

	//@ requires num >= 0;
	//@ ensures \result >= 0 && \result <= 9;
 
 
	public static int firstDigit(int num) {
		int first = 1;
		//@ maintaining first >= 1;
		//@ maintaining 1 < j && j - 1 <= num + 1;  
 
		//@ decreases num - j + 1;
		for (int j = 2; j <= num; j++) {
			first *= j;
		}
		int result = 0;
		//@ maintaining first >= 0;
		//@ maintaining 0 <= result && result <= 9;
 
		//@ decreases first;
		while (first > 0) {
			result = first % 10;
			first /= 10;
		}
		return result;
	}
}