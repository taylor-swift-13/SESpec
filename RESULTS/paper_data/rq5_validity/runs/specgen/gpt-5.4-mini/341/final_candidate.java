import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindDivisor {

	//@ ensures \result >= 0;
	//@ ensures \result <= (z < 0 ? -z : z);
	public static int findDivisor(int num, int z) {
		if (z < 0) {
			z = -z;
		}
		int result = 0;
		//@ maintaining 1 <= loop && loop <= z + 1;
		//@ maintaining result >= 0;
		//@ maintaining result <= loop - 1;
		//@ decreases z - loop + 1;
		for (int loop = 1; loop <= z; loop++) {
			if (num % loop == 0) {
				result = result + 1;
			}
		}
		return result;
	}
}