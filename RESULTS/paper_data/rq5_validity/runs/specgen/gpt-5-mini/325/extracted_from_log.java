import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FirstDigit {

	/*@ public normal_behavior
	  @   requires num >= 0;
	  @   ensures 0 <= \result && \result <= 9;
	  @   // \result is the most significant decimal digit of num! (product 1..num, empty product = 1)
	  @   ensures (\exists int f; f == (\product int i; 1 <= i && i <= num; i)
	  @                     && (\exists int m; m >= 0 &&
	  @                             f / (\product int t; 1 <= t && t <= m; 10) < 10
	  @                          && f / (\product int t; 1 <= t && t <= m; 10) == \result));
	  @*/
	public static int firstDigit(int num) {
		int first = 1;
		/*@ 
		  @   // invariant: 'first' is the product of integers 1..(j-1)
		  @   maintaining 2 <= j && j - 1 <= num + 1;  
 
		  @   decreases num - j + 1;
		  @*/
		for (int j = 2; j <= num; j++) {
			first *= j;
		}
		int result = 0;
		/*@
		  @   // simple invariants while extracting the most significant digit
 
 
		  @   // relate 'first' and the full factorial f: first is a suffix of f in base 10
 
		  @                          && (\exists int m; m >= 0 && f / (\product int t; 1 <= t && t <= m; 10) >= first));
		  @   decreases first;
		  @*/
		while (first > 0) {
			result = first % 10;
			first /= 10;
		}
		return result;
	}
}