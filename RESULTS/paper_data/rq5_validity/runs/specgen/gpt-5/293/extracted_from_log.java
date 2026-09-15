import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class GetPell {

	//@ requires seed >= 1;
	//@ ensures 0 <= \result && \result < 1000000000;
	//@ ensures (\exists int[] s; s != null && s.length == seed + 1 && s[0] == 0 && s[1] == 1
	//@          && (\forall int k; 2 <= k && k <= seed; s[k] == (2 * s[k - 1] + s[k - 2]) % 1000000000)
	//@          && \result == s[seed]);
	public static int getPell(int seed) {
		int[] arr = new int[seed + 1];
		arr[0] = 0;
		arr[1] = 1;
		//@ maintaining 2 <= p && p <= seed + 1;
		//@ maintaining arr.length == seed + 1;
		//@ maintaining arr[0] == 0 && arr[1] == 1;
		//@ maintaining (\forall int k; 2 <= k && k < p; arr[k] == (2 * arr[k - 1] + arr[k - 2]) % 1000000000);
		//@ maintaining (\forall int k; 0 <= k && k < p; 0 <= arr[k] && arr[k] < 1000000000);
		//@ decreases seed - p + 1;
		for (int p = 2; p <= seed; p++) {
			arr[p] = (2 * arr[p - 1]
					+ arr[p - 2]) % 1000000000;
		}
		return arr[seed];
	}
}