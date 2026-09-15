import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class Divisor {

	/*@ spec_public @*/
	/*@ requires number >= 1;
	  @ ensures \result == (\num_of int i; 1 <= i && i <= number; number % i == 0);
	  @ ensures 1 <= \result && \result <= number;
	  @*/
	public static int divisor(int number) {
		int div = 0;
		//@ maintaining 1 <= index && index <= number + 1;
		//@ maintaining 0 <= div && div <= index - 1;
		//@ maintaining div == (\num_of int i; 1 <= i && i < index; number % i == 0);
		//@ decreases number - index + 1;
		for (int index = 1; index <= number; index++) {
			if (number % index == 0) {
				div++;
			}
		}
		return div;
	}
}