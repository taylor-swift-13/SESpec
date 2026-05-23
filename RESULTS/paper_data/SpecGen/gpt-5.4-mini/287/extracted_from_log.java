import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class JacobsthalNum {

	//@ requires c >= 1;
	//@ ensures \result >= 0;
	//@ ensures \result == jacobsthalNum(c);
	public static int jacobsthalNum(int c) {
		int j[] = new int[c + 1];
		j[0] = 0;
		j[1] = 1;
		//@ maintaining 2 <= p && p <= c + 1;
		//@ maintaining j[0] == 0 && j[1] == 1;
		//@ maintaining (\forall int q; 2 <= q && q < p; j[q] == j[q - 1] + 2 * j[q - 2]);
		//@ decreases c - p + 1;
		for (int p = 2; p <= c; p++) {
			j[p] = j[p - 1]
					+ 2 * j[p - 2];
		}
		return j[c];
	}
}