import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class EvenBitSetNumber {

	//@ ensures num <= 0 ==> \result == num;
	//@ ensures num > 0 ==> \result >= num;
	//@ ensures num > 0 ==> (\forall int k; 0 <= k && k < 32;
	//@                         (((\result >>> k) & 1) ==
	//@                          (((num >>> k) & 1) | ((((k % 2) == 1) && ((num >>> k) > 0)) ? 1 : 0))));
	public static int evenBitSetNumber(int num) {
		int result = 0;
		int max = 0;
		int sum = num;
		//@ maintaining 0 <= result && result <= 31;
		//@ maintaining sum == (num >>> result);
		//@ maintaining (\forall int k; 0 <= k && k < result;
		//@                 (((k % 2) == 1) ==> (((max >>> k) & 1) == 1)) &&
		//@                 (((k % 2) == 0) ==> (((max >>> k) & 1) == 0)));
		//@ maintaining (\forall int k; result <= k && k < 32; ((max >>> k) & 1) == 0);
		//@ decreases sum;
		while (sum > 0) {
			if (result % 2 == 1) {
				max |= (1 << result);
			}
			result++;
			sum >>= 1;
		}
		return (num | max);
	}
}