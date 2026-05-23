import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class ComputeLastDigit {

	/*@ requires true;
	  @ ensures (n == c) ==> (\result == 1);
	  @ ensures ((c - n) >= 5) ==> (\result == 0);
	  @ ensures (n != c && (c - n) < 5) ==> (0 <= \result && \result < 10);
	  @*/
	public static int computeLastDigit(int n, int c) {
		int result = 1;
		if (n == c) {
			return 1;
		} else if ((c - n) >= 5) {
			return 0;
		} else {
 
 
 
			  @     (\product int i; n + 1 <= i && i < var; (i % 10)) % 10;
 
			  @*/
			for (int var = n + 1; var < c + 1; var++) {
				result = (result * (var % 10)) % 10;
			}
			return result % 10;
		}
	}
}