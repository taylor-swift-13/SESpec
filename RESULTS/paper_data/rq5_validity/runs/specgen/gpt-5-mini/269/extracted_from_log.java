import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class CountNoOfWays {

	/*@ 
	  @ requires dim >= 2 && w >= 1;
	  @ ensures 0 <= \result && \result < 1000000007;
	  @ ensures (\exists int[] dv; dv != null && dv.length == dim+1 &&
	  @            dv[0] == 1 &&
	  @            dv[1] == w &&
	  @            (dim >= 2 ==> dv[2] == w * w) &&
	  @            (\forall int k; 3 <= k && k <= dim; dv[k] == ((w - 1) * (dv[k-1] + dv[k-2])) % 1000000007) &&
	  @            dv[dim] == \result);
	  @*/
	public static int countNoOfWays(int dim, int w) {
		int count = 1000000007;
		int div[] = new int[dim + 1];
		div[0] = 1;
		div[1] = w;
		div[2] = w * w;
		/*@ 
		  @ maintaining div.length == dim + 1;
		  @ maintaining div[0] == 1 && div[1] == w && (dim >= 2 ==> div[2] == w * w);
		  @ maintaining (\forall int k; 3 <= k && k < d; div[k] == ((w - 1) * (div[k-1] + div[k-2])) % 1000000007);
		  @ maintaining 3 <= d && d - 1 <= dim;  
		  @ decreases dim - d + 1;
		  @*/
		for (int d = 3; d <= dim; d++) {
			//@ assume 3 <= d && d < div.length;
			div[d] = ((w - 1)
					* (div[d - 1] + div[d - 2])) % count;
		}
		return div[dim];
	}
}