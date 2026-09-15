import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class JacobsthalLucas {

	/*@ 
	  @ requires c >= 1;
 
	  @ ensures c == 1 ==> \result == 1;
	  @*/
	public static int jacobsthalLucas(int c) {
		int j[] = new int[c + 1];
		j[0] = 2;
		j[1] = 1;
		/*@ maintaining j.length == c + 1;
		  @ maintaining j[0] == 2 && j[1] == 1;
		  @ maintaining 2 <= d && d <= c + 1;
		  @ decreases c + 1 - d;
		  @*/
		for (int d = 2; d <= c; d++) {
			j[d] = j[d - 1]
					+ 2 * j[d - 2];
		}
		return j[c];
	}
}