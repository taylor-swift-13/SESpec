import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class JacobsthalLucas {

	/*@ 
	  @ requires c >= 1;
	  @ 
	  @ ensures \exists int[] M; M.length == c + 1
	  @                     && M[0] == 2
	  @                     && M[1] == 1
	  @                     && (\forall int i; 2 <= i && i <= c; M[i] == M[i-1] + 2 * M[i-2])
	  @                     && \result == M[c];
	  @*/
	public static int jacobsthalLucas(int c) {
		int N[] = new int[c + 1];
		N[0] = 2;
		N[1] = 1;
		/*@ 
		  @ maintaining 2 <= p && p <= c + 1;
		  @ maintaining N.length == c + 1;
		  @ maintaining N[0] == 2 && N[1] == 1;
		  @ maintaining (\forall int i; 2 <= i && i < p; N[i] == N[i-1] + 2 * N[i-2]);
		  @ decreases c - p + 1;
		  @*/
		for (int p = 2; p <= c; p++) {
			N[p] = N[p - 1]
					+ 2 * N[p - 2];
		}
		return N[c];
	}
}