import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FirstDigit {

	/*@
	  @ requires num >= 0 && num <= 12; // restrict to values where factorial fits into an int (avoids overflow)
	  @ ensures 1 <= \result && \result <= 9;
 
	  @          (\exists int k; k >= 1 &&
	  @              f / (\product int t; 1 <= t && t <= k; 10) >= 1 &&
	  @              f / (\product int t; 1 <= t && t <= k; 10) < 10 &&
	  @              \result == f / (\product int t; 1 <= t && t <= k; 10)
	  @          )
	  @         );
	  @*/
	public static /*@ spec_public @*/ int firstDigit(int num) {
		int first = 1;
		//@ maintaining 1 <= first;
		//@ maintaining 2 <= c && c - 1 <= num+1;  
 
		//@ decreases num - c + 1;
		for (int c = 2; c <= num; c++) {
			first *= c;
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