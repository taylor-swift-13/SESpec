import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class JacobsthalNum {

	//@ requires j >= 0;
	//@ ensures \result >= 0;
	//@ ensures j == 0 ==> \result == 0;
	//@ ensures j == 1 ==> \result == 1;
	//@ ensures j > 1 ==> \result == jacobsthalNum(j - 1) + 2 * jacobsthalNum(j - 2);
	public static int jacobsthalNum(int j) {
		int r[] = new int[j + 1];
		r[0] = 0;
		r[1] = 1;
		//@ maintaining 2 <= p && p <= j + 1;
		//@ maintaining r[0] == 0 && r[1] == 1;
		//@ maintaining (\forall int i; 2 <= i && i < p; r[i] == r[i - 1] + 2 * r[i - 2]);
		//@ decreases j - p + 1;
		for (int p = 2; p <= j; p++) {
			r[p] = r[p - 1]
					+ 2 * r[p - 2];
		}
		return r[j];
	}
}