import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class CountDivisors {

    //@ requires num >= 1;
    //@ ensures \result.equals("Even") || \result.equals("Odd");
    //@ ensures num == 1 ==> \result.equals("Odd");
	public static String countDivisors(int num) {
		int result = 0;
		//@ maintaining 1 <= c && c <= num + 1;
		//@ maintaining 0 <= result && result <= num;
		//@ decreases num - c + 1;
		for (int c = 1; c <= num; c++) {
			if (num % c == 0) {
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