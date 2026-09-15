import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class JacobsthalLucas {

	/*@
	  @ requires c >= 1;
	  @
	  @ // Base cases
	  @ ensures c == 1 ==> \result == 1;
	  @ ensures c == 2 ==> \result == 5;
	  @
	  @ // Recursive characterization for c >= 2
	  @ ensures c >= 2 ==> \result == jacobsthalLucas(c-1) + 2 * jacobsthalLucas(c-2);
	  @*/
	public static int jacobsthalLucas(int c) {
		int j[] = new int[c + 1];
		j[0] = 2;
		j[1] = 1;
		//@ maintaining j.length == c + 1;
		//@ maintaining j[0] == 2 && j[1] == 1;
		//@ maintaining 2 <= p && p <= c+1 ==> (\forall int q; 2 <= q && q < p; j[q] == j[q-1] + 2 * j[q-2]);
		//@ decreases c - p + 1;
		for (int p = 2; p <= c; p++) {
			j[p] = j[p - 1]
					+ 2 * j[p - 2];
		}
		return j[c];
	}
}