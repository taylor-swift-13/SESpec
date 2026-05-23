import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindMaxVal {

    /*@ spec_public @*/
    //@ requires p != 0;
    //@ ensures value < 1 ==> \result == 0;
    //@ ensures (\exists int c; 1 <= c && c <= value; c % p == dy)
    //@          ==> (1 <= \result && \result <= value && \result % p == dy
    //@               && (\forall int t; 1 <= t && t <= value && t % p == dy; t <= \result));
    //@ ensures !(\exists int c; 1 <= c && c <= value; c % p == dy) ==> \result == 0;
	public static int findMaxVal(int value, int p, int dy) {
		int result = 0;
        //@ maintaining 1 <= c && c <= value + 1;
        //@ maintaining 0 <= result;
        //@ maintaining (\forall int t; 1 <= t && t < c && t % p == dy; t <= result);
        //@ maintaining (\exists int t; 1 <= t && t < c && t % p == dy)
        //@             ==> (1 <= result && result < c && result % p == dy);
        //@ maintaining !(\exists int t; 1 <= t && t < c && t % p == dy) ==> result == 0;
        //@ decreases ((value - c + 1) < 0 ? 0 : (value - c + 1));
		for (int c = 1; c <= value; c++) {
			if ((c % p) == dy) {
				result = c;
			}
		}
		return result;
	}
}