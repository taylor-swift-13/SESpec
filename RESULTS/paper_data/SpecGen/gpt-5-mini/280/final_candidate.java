import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class CountDivisors {

	/*@
	  @ requires number >= 1;
	  @ ensures \result.equals("Even") || \result.equals("Odd");
	  @*/
	public static String countDivisors(int number) {
		int result = 0;
		/*@
		  @ maintaining 1 <= c && c <= number + 1;
		  @ decreases number + 1 - c;
		  @*/
		for (int c = 1; c <= number; c++) {
			if (number % c == 0) {
				result++;
			}
		}
		if (result % 2 == 0) {
			return "Even";
		} else {
			return "Odd";
		}
	}
}