import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class CountDivisors {

	//@ ensures \result == "Even" || \result == "Odd";
	public static String countDivisors(int num) {
		int result = 0;
		//@ maintaining true;
		for (int index = 1; index <= num; index++) {
			if (num % index == 0) {
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