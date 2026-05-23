import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class GetPell {

	/*@ 
	  @ requires seed >= 1;
	  @ ensures (\exists int[] pp;
	  @              pp.length == seed + 1
	  @           && pp[0] == 0
	  @           && pp[1] == 1
	  @           && (\forall int k; 2 <= k && k <= seed;
	  @                   pp[k] == (2 * pp[k - 1] + pp[k - 2]) % 1000000000)
	  @           && \result == pp[seed]);
	  @*/
	public static int getPell(int seed) {
		int[] p = new int[seed + 1];
		p[0] = 0;
		p[1] = 1;
		//@ maintaining p.length == seed + 1;
		//@ maintaining p[0] == 0 && p[1] == 1;
		//@ maintaining 2 <= count && count <= seed + 1;
		//@ maintaining (\forall int k; 2 <= k && k < count; p[k] == (2 * p[k - 1] + p[k - 2]) % 1000000000);
		//@ decreases seed - count + 1;
		for (int count = 2; count <= seed; count++) {
			p[count] = (2 * p[count - 1]
					+ p[count - 2]) % 1000000000;
		}
		return p[seed];
	}
}