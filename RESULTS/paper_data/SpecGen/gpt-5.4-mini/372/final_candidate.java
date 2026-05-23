import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class Divisor {

	//@ requires num >= 0;
	//@ ensures \result >= 0;
	//@ ensures \result == (\num_of int c; 1 <= c && c <= num; num % c == 0);
	public static int divisor(int num) {
		int div = 0;
		//@ maintaining 0 <= c && c <= num + 1;
		//@ maintaining 0 <= div;
 
		//@ decreases num - c + 1;
		for (int c = 1; c <= num; c++) {
			if (num % c == 0) {
				div++;
			}
		}
		return div;
	}
}
