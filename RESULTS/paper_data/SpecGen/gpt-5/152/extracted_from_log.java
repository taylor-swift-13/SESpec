import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class GetNumber {

    //@ requires number >= 0;
    //@ ensures (p <= 0 || p > number) ==> \result == 0;
    //@ ensures (1 <= p && p <= ((number + 1) / 2)) ==> \result == 2*p - 1;
    //@ ensures (((number + 1) / 2) < p && p <= number) ==> \result == 2 * (p - ((number + 1) / 2));
    //@ ensures (\result == 0) || (1 <= \result && \result <= number);
	public static int getNumber(int number, int p) {
		int result[] = new int[number];
		int b[] = new int[number];
		int c, j = 0;
        //@ maintaining 0 <= c && c <= number;
        //@ maintaining (\forall int i; 0 <= i && i < c; result[i] == i + 1);
        //@ decreases number - c;
		for (c = 0; c < number; c++) {
			result[c] = c + 1;
		}
        //@ maintaining 0 <= c && c <= number;
        //@ maintaining 0 <= j && j <= c;
        //@ maintaining (\forall int i; 0 <= i && i < c; b[i] == result[i]);
        //@ maintaining (\forall int i; 0 <= i && i < number; result[i] == i + 1);
        //@ decreases number - c;
		for (c = 0; c < number; c++) {
			b[c] = result[c];
			if (result[c] % 2 != 0) {
				j++;
				if (j == p) {
					return result[c];
				}
			}
		}
        //@ maintaining 0 <= c && c <= number;
        //@ maintaining 0 <= j && j <= number;
        //@ maintaining (\forall int i; 0 <= i && i < c; b[i] == result[i]);
        //@ maintaining (\forall int i; 0 <= i && i < number; result[i] == i + 1);
        //@ decreases number - c;
		for (c = 0; c < number; c++) {
			b[c] = result[c];
			if (result[c] % 2 == 0) {
				j++;
				if (j == p) {
					return result[c];
				}
			}
		}
		return 0;
	}
}