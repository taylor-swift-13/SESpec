import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class ComputeLastDigit {

	//@ ensures (\result == 1 && n == c) || (\result == 0 && (c - n) > 5) || (0 - 1 <= \result && \result < 10);  
	public static int computeLastDigit(int n, int c) {
		int result = 1;
		if (n == c) {
			return 1;
		} else if ((c - n) >= 5) {
			return 0;
		} else {
 
 
 
			//@ decreases c + 1 - index;
			for (int index = n + 1; index < c + 1; index++) {
				result = (result * (index % 10)) % 10;
			}
			return result % 10;
		}
	}
}