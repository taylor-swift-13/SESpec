import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class CountDivisors {

	/*@ 
	  @ requires num >= 1;
	  @ ensures \result != null && (\result == "Even" || \result == "Odd");
	  @*/
	public static /*@ spec_public @*/ String countDivisors(int num) {
		int result = 0;
		/*@ 
		  @ maintaining 1 <= index && index <= num + 1;
 
		  @*/
		for (int index = 1; index <= num; index++) {
			if (num % index == 0) {
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