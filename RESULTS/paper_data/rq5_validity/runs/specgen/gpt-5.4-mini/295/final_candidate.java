import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindLucas {

	//@ requires num >= 1;
	//@ ensures num == 0 ==> \result == 2;
	//@ ensures num == 1 ==> \result == 1;
	//@ ensures num >= 2 ==> \result > 0;
	public static int findLucas(int num) {
		int[] result = new int[num + 1];
		result[0] = 2;
		//@ assume result.length > 1;
		result[1] = 1;
		//@ maintaining 2 <= l && l <= num + 1;
		//@ maintaining result[0] == 2 && result[1] == 1;
		//@ maintaining (\forall int i; 2 <= i && i < l; result[i] > 0);
		//@ decreases num - l + 1;
		for (int l = 2; l <= num; l++) {
			result[l] = result[l - 1]
					+ result[l - 2];
		}
		return result[num];
	}
}