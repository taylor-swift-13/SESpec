import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class CountDigit {

    //@ requires value >= 0;
    //@ ensures \result >= 0;
    //@ ensures value == 0 ==> \result == 0;
    //@ ensures value > 0 ==> (\result > 0);
	public static int countDigit(int value) {
		int result = 0;
		//@ maintaining value >= 0;
		//@ maintaining result >= 0;
		//@ decreases value;
		while (value > 0) {
			value /= 10;
			result++;
		}
		return result;
	}
}