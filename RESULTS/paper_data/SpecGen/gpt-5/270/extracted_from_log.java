import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class CountNoOfWays {

	//@ requires count >= 2;
	//@ ensures true;
	public static int countNoOfWays(int count, int m) {
		int w = 1000000007;
		int div[] = new int[count + 1];
		div[0] = 1;
		div[1] = m;
		div[2] = m * m;
		//@ maintaining div != null && div.length == count + 1;
		//@ maintaining div[0] == 1 && div[1] == m && div[2] == m * m;
		//@ maintaining 3 <= d && d <= count + 1;
		//@ decreases count - d + 1;
		for (int d = 3; d <= count; d++) {
			div[d] = ((m - 1)
					* (div[d - 1] + div[d - 2])) % w;
		}
		return div[count];
	}
}