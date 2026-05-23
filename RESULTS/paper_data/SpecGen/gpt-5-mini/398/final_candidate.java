import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class CountDigit {

	/*@ public normal_behavior
	  @   requires true;
	  @   // If the input number is non-positive the method returns 0 (no digits counted).
	  @   ensures \result == 0 <==> \old(number) <= 0;
	  @   // If the input number is positive, the result is at least 1.
	  @   ensures \old(number) > 0 ==> \result >= 1;
	  @*/
	public static int countDigit(int number) {
		int ret = 0;
 
 
 
 
		  @*/
		while (number > 0) {
			number /= 10;
			ret++;
		}
		return ret;
	}
}
