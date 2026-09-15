import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class Divisor {

	//@ requires num >= 0;
	//@ assignable \nothing;
	//@ ensures \result == (\num_of int c; 1 <= c && c <= num; num % c == 0);
	public static int divisor(int num) {
		int div = 0;
		//@ maintaining 1 <= c && c <= num + 1;
		//@ maintaining div == (\num_of int d; 1 <= d && d < c; num % d == 0);
		//@ decreases num - c + 1;
		for (int c = 1; c <= num; c++) {
			if (num % c == 0) {
				div++;
			}
		}
		return div;
	}
}