import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class GetPell {

	/*@ requires seed >= 1;
	  @ ensures \result >= 0;
	  @ ensures \result < 1000000000;
	  @ ensures \exists int[] p;
	  @*/
	public static int getPell(int seed) {
		int[] p = new int[seed + 1];
		p[0] = 0;
		p[1] = 1;
		/*@ maintaining 2 <= count && count <= seed + 1;
		  @ maintaining p[0] == 0;
		  @ maintaining p[1] == 1;
		  @ maintaining (\forall int i; 2 <= i && i < count;
		  @                p[i] == (2 * p[i - 1] + p[i - 2]) % 1000000000);
		  @ decreases seed - count + 1;
		  @*/
		for (int count = 2; count <= seed; count++) {
			p[count] = (2 * p[count - 1]
					+ p[count - 2]) % 1000000000;
		}
		return p[seed];
	}
}