import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindDivisor {

	//@ ensures z == (\old(z) < 0 ? -\old(z) : \old(z));
	//@ ensures \result == (\num_of int d; 1 <= d && d <= z; n % d == 0);
	public static int findDivisor(int n, int z) {
		if (z < 0) {
			z = -z;
		}
		int result = 0;
		//@ maintaining 1 <= loop;
		//@ maintaining result == (\num_of int d; 1 <= d && d < loop; n % d == 0);
		//@ decreases z - loop + 1;
		for (int loop = 1; loop <= z; loop++) {
			if (n % loop == 0) {
				result = result + 1;
			}
		}
		return result;
	}
}