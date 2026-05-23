import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class JacobsthalLucas {

	//@ requires c >= 1;
	//@ ensures c == 1 ==> \result == 1;
	public static int jacobsthalLucas(int c) {
		int N[] = new int[c + 1];
		N[0] = 2;
		N[1] = 1;
		//@ maintaining N.length == c + 1;
		//@ maintaining N[0] == 2 && N[1] == 1;
		//@ maintaining 2 <= p && p <= c + 1;
		//@ decreases c - p + 1;
		for (int p = 2; p <= c; p++) {
			N[p] = N[p - 1]
					+ 2 * N[p - 2];
		}
		return N[c];
	}
}