import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class CountDigit {

	/*@ public normal_behavior
	  @   requires true;
	  @   // result is non-negative
	  @   ensures \result >= 0;
	  @   // if the original value is non-positive, the result is 0
	  @   ensures \old(value) <= 0 ==> \result == 0;
	  @   // if the original value is positive, the result is positive
	  @   ensures \old(value) > 0 ==> \result > 0;
	  @*/
	public static int countDigit(int value) {
		int result = 0;
 
 
		  @ // result counts how many times we divided original value by 10 until value became 0
 
 
		  @*/
		while (value > 0) {
			value /= 10;
			result++;
		}
		return result;
	}
}
