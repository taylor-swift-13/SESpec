import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class EvenBitSetNumber {

	//@ requires num >= 0;
	//@ ensures (\exists int k; k >= 0 && (num >> k) == 0 && (\forall int j; 0 <= j && j < k ==> (num >> j) != 0)
	//@          && (\forall int i; 0 <= i
	//@               ==> (((\result & (1 << i)) != 0)
	//@                    <==> (((num & (1 << i)) != 0) || (i < k && i % 2 == 1)))));
	public static int evenBitSetNumber(int num) {
		int result = 0;
		int max = 0;
		int sum = num;
		//@ maintaining result >= 0 && sum >= 0;
		//@ maintaining sum == (num >> result);
		//@ maintaining (\forall int i; 0 <= i && i < result
		//@              ==> (((max & (1 << i)) != 0) <==> (i % 2 == 1)));
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