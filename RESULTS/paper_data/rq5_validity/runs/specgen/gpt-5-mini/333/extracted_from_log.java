import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class ComputeLastDigit {

    /*@ 
      @ requires true;
      @ ensures 0 <= \result && \result < 10;
      @ ensures n >= c ==> \result == 1;
 
 
      @           \result == (\product int v; n+1 <= v && v <= c; v % 10) % 10;
      @*/
	public static int computeLastDigit(int n, int c) {
		int result = 1;
		if (n == c) {
			return 1;
		} else if ((c - n) >= 5) {
			return 0;
		} else {
			/*@
 
			  @ maintaining 0 <= result && result < 10;
 
			  @ decreases c + 1 - var;
			  @*/
			for (int var = n + 1; var < c + 1; var++) {
				result = (result * (var % 10)) % 10;
			}
			return result % 10;
		}
	}
}