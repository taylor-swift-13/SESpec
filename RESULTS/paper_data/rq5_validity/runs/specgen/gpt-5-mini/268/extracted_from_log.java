import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class CountNoOfWays {

	/*@
	  @ requires count >= 0;
	  @
	  @ // Basic bounds and base cases
 
	  @ ensures count == 0 ==> \result == 1;
	  @ ensures count == 1 ==> \result == w;
 
	  @*/
	public static int countNoOfWays(int count, int w) {
		int result = 1000000007;
		int div[] = new int[count + 1];
		/*@ assume div.length == count + 1; @*/
		div[0] = 1;
		/*@ assume 1 < div.length; @*/
		div[1] = w;
		/*@ assume 2 < div.length; @*/
		div[2] = w * w;
		/*@
		  @ // Simple loop invariant: loop index stays in the expected range
		  @ maintaining 3 <= d && d <= count + 1;
		  @ decreases count - d + 1;
		  @*/
		for (int d = 3; d <= count; d++) {
			/*@ assume d < div.length && d - 1 < div.length && d - 2 < div.length; @*/
			div[d] = ((w - 1)
					* (div[d - 1] + div[d - 2])) % result;
		}
		return div[count];
	}
}