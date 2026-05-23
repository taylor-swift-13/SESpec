import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class CountDigit {

    //@ ensures \result >= 0;
    //@ ensures (\old(number) <= 0) <==> (\result == 0);
    //@ ensures \old(number) > 0 ==> 1 <= \result && \result <= 10;
	public static int countDigit(int number) {
		int ret = 0;
		//@ maintaining ret >= 0;
		//@ maintaining number >= 0;
		//@ decreases number;
		while (number > 0) {
			number /= 10;
			ret++;
		}
		return ret;
	}
}