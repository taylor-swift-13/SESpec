import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class CountDivisors {

    //@ requires number >= 0;
    //@ ensures \result != null;
    //@ ensures \result.equals("Even") || \result.equals("Odd");
    //@ ensures number == 0 ==> \result.equals("Even");
	public static String countDivisors(int number) {
		int result = 0;
        //@ maintaining 1 <= c && c <= number + 1;
        //@ maintaining 0 <= result && result <= c - 1;
        //@ decreases number - c + 1;
		for (int c = 1; c <= number; c++) {
			if (number % c == 0) {
				result++;
			}
		}
		if (result % 2 == 0) {
			return "Even";
		} else {
			return "Odd";
		}
	}
}