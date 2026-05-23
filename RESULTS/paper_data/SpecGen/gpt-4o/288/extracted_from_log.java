import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class JacobsthalNum {

	//@ requires j >= 0;
	//@ ensures \result == (j == 0 ? 0 : (j == 1 ? 1 : jacobsthalNum(j - 1) + 2 * jacobsthalNum(j - 2)));
	public static int jacobsthalNum(int j) {
		int ret[] = new int[j + 1];
		ret[0] = 0;
		ret[1] = 1;
		//@ maintaining 2 <= p && p <= j + 1;
		//@ maintaining (\forall int k; 0 <= k && k < p; ret[k] == (k == 0 ? 0 : (k == 1 ? 1 : ret[k - 1] + 2 * ret[k - 2])));
		//@ decreases j - p + 1;
		for (int p = 2; p <= j; p++) {
			ret[p] = ret[p - 1]
					+ 2 * ret[p - 2];
		}
		return ret[j];
	}
}