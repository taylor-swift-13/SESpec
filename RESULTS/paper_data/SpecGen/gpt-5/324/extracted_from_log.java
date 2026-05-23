import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FirstDigit {

    //@ requires number >= 0;
    //@ ensures 0 <= \result && \result <= 9;
    //@ ensures (number == 0 || number == 1) ==> \result == 1;
	public static int firstDigit(int number) {
		int first = 1;
        //@ maintaining 2 <= c && c <= number + 1;
        //@ decreases number - c + 1;
		for (int c = 2; c <= number; c++) {
			first *= c;
		}
		int result = 0;
        //@ maintaining 0 <= result && result <= 9;
        //@ decreases first;
		while (first > 0) {
			result = first % 10;
			first /= 10;
		}
		return result;
	}
}