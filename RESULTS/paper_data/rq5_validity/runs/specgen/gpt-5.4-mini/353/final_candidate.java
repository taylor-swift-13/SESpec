import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class EvenBitSetNumber {

	//@ requires num >= 0;
	//@ ensures \result >= num;
	//@ ensures (\forall int i; 0 <= i && i < 31; (((num >>> i) & 1) == 1 && (i % 2 == 1)) ==> (((\result >>> i) & 1) == 1));
	public static int evenBitSetNumber(int num) {
		int result = 0;
		int max = 0;
		int sum = num;
		//@ maintaining 0 <= result;
		//@ maintaining 0 <= sum;
		//@ maintaining sum == (num >>> result);
		//@ maintaining 0 <= max;
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