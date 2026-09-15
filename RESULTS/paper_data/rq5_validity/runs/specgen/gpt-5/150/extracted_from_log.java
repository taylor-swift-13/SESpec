import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class GetNumber {

	//@ requires value >= 0;
	//@ ensures (p < 1 || p > value) ==> \result == 0;
	//@ ensures 1 <= p && p <= ((value + 1) / 2) ==> \result == 2*p - 1;
	//@ ensures ((value + 1) / 2) < p && p <= value ==> \result == 2*(p - ((value + 1) / 2));
	//@ ensures 0 <= \result && \result <= value;
	public static int getNumber(int value, int p) {
		int result[] = new int[value];
		int b[] = new int[value];
		int c, j = 0;
		//@ maintaining 0 <= c && c <= value;
		//@ maintaining (\forall int i; 0 <= i && i < c; result[i] == i + 1);
		//@ decreases value - c;
		for (c = 0; c < value; c++) {
			result[c] = c + 1;
		}
		//@ maintaining 0 <= c && c <= value;
		//@ maintaining (\forall int i; 0 <= i && i < value; result[i] == i + 1);
		//@ maintaining (\forall int i; 0 <= i && i < c; b[i] == result[i]);
		//@ maintaining j == (c + 1) / 2;
		//@ maintaining 0 <= j && j <= c;
		//@ decreases value - c;
		for (c = 0; c < value; c++) {
			b[c] = result[c];
			if (result[c] % 2 != 0) {
				j++;
				if (j == p) {
					return result[c];
				}
			}
		}
		//@ maintaining 0 <= c && c <= value;
		//@ maintaining (\forall int i; 0 <= i && i < value; result[i] == i + 1);
		//@ maintaining (\forall int i; 0 <= i && i < c; b[i] == result[i]);
		//@ maintaining j == ((value + 1) / 2) + (c / 2);
		//@ maintaining ((value + 1) / 2) <= j && j <= ((value + 1) / 2) + c;
		//@ decreases value - c;
		for (c = 0; c < value; c++) {
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