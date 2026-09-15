import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class GetNumber {

	//@ requires number >= 0 && p > 0;
	//@ ensures \result == 0 || (1 <= \result && \result <= number);
	//@ ensures \result != 0 ==> (\exists int c; 0 <= c && c < number; 
	//@                           ((\result % 2 != 0 && \result == c + 1) || (\result % 2 == 0 && \result == c + 1)));
	//@ ensures \result != 0 ==> (\num_of int c; 0 < c && c < number; (c - 1) % 2 != 0) <= p || (\num_of int c; 0 - 1 <= c && c < number; (c - 1) % 2 == 0) <= p;  
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
		//@ maintaining 0 <= j && j <= number;
		//@ maintaining (\forall int i; 0 <= i && i < c; b[i] == result[i]);
		//@ maintaining (\forall int i; 0 <= i && i < c; (result[i] % 2 != 0) ==> (j >= (\num_of int k; 0 <= k && k <= i; result[k] % 2 != 0)));
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
		//@ maintaining 0 <= j && j - 1 <= 2 * number;  
		//@ maintaining (\forall int i; 0 <= i && i < c; b[i] == result[i]);
		//@ maintaining (\forall int i; 0 <= i && i < c; (result[i] % 2 == 0) ==> (j >= (\num_of int k; 0 <= k && k <= i; result[k] % 2 == 0)));
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
