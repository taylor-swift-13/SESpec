import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FirstDigit {

	//@ requires number >= 0;
	//@ ensures \result >= 0 && \result <= 9;
	public static int firstDigit(int number) {
		int first = 1;
 
 
 
		//@ decreases number - c + 1;
		for (int c = 2; c <= number; c++) {
			first *= c;
		}
		int result = 0;
		//@ maintaining first + 1 >= 0;  
		//@ maintaining 0 <= result && result <= 9;
		//@ maintaining first == 0 || first > 0;
		//@ decreases first;
		while (first > 0) {
			result = first % 10;
			first /= 10;
		}
		return result;
	}
}