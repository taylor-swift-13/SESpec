import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class CountNoOfWays {

	/*@
	  @ requires count >= 2 && m >= 0;
 
 
	  @*/
	public static int countNoOfWays(int count, int m) {
		int w = 1000000007;
		int div[] = new int[count + 1];
		div[0] = 1;
		div[1] = m;
		div[2] = m * m;
		/*@
		  @ // simple loop invariants ensuring indices stay in range
		  @ maintaining 3 <= d && d <= count + 1;
		  @ maintaining d <= div.length;
		  @ maintaining d - 1 < div.length && d - 2 < div.length;
		  @ // keep initial entries within modulus bounds
		  @ maintaining 0 <= div[0] && div[0] < w;
		  @ maintaining 0 <= div[1] && div[1] < w;
 
		  @ decreases count - d + 1;
		  @*/
		for (int d = 3; d <= count; d++) {
			div[d] = ((m - 1)
					* (div[d - 1] + div[d - 2])) % w;
		}
		return div[count];
	}
}