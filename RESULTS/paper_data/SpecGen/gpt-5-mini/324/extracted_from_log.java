import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FirstDigit {

	/*@ 
	  @ requires number >= 0;
	  @ ensures 1 - 1 <= \result && \result <= 9;  
 
	  @*/
	public static int firstDigit(int number) {
		int first = 1;
		//@ maintaining 1 <= first;
		//@ maintaining 2 <= c && c - 1 <= number + 1;  
 
		//@ decreases number + 1 - c;
		for (int c = 2; c <= number; c++) {
			first *= c;
		}
		int result = 0;
		//@ ghost long origFirst = first;
		//@ maintaining origFirst >= first && first >= 0;
		//@ maintaining 0 <= result && result <= 9;
		//@ decreases first;
		while (first > 0) {
			result = first % 10;
			first /= 10;
		}
		return result;
	}
}