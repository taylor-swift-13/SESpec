import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class Divisor {

    //@ ensures \result == (\sum int i; 1 <= i && i <= number && number % i == 0; 1);
    //@ ensures number < 1 ==> \result == 0;
    //@ ensures number >= 1 ==> 1 <= \result && \result <= number;
    //@ ensures \result >= 0;
	public static int divisor(int number) {
		int div = 0;
        //@ maintaining c >= 1;
        //@ maintaining div == (\sum int i; 1 <= i && i < c && number % i == 0; 1);
        //@ maintaining div >= 0;
		for (int c = 1; c <= number; c++) {
			if (number % c == 0) {
				div++;
			}
		}
		return div;
	}
}