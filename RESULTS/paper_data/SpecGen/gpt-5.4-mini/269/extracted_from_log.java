import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class CountNoOfWays {

	/*@ requires dim >= 2;
	  @ requires w >= 0;
 
	  @*/
	public static int countNoOfWays(int dim, int w) {
		int count = 1000000007;
		int div[] = new int[dim + 1];
		div[0] = 1;
		div[1] = w;
		div[2] = w * w;
		/*@ maintaining 3 <= d && d <= dim + 1;
		  @ maintaining div.length == dim + 1;
		  @ maintaining div[0] == 1;
		  @ maintaining div[1] == w;
		  @ maintaining div[2] == w * w;
		  @ decreases dim - d + 1;
		  @*/
		for (int d = 3; d <= dim; d++) {
			div[d] = ((w - 1)
					* (div[d - 1] + div[d - 2])) % count;
		}
		return div[dim];
	}
}