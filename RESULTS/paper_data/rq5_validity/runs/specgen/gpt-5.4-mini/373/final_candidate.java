import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class Divisor {

	//@ requires number >= 0;
	//@ ensures \result >= 0;
 
	public static int divisor(int number) {
		int div = 0;
		//@ maintaining 0 <= div;
		//@ maintaining 1 <= index;
		//@ maintaining index <= number + 1;
 
		//@ decreases number - index + 1;
		for (int index = 1; index <= number; index++) {
			if (number % index == 0) {
				div++;
			}
		}
		return div;
	}
}
