import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class EvenBitSetNumber {

	//@ requires num >= 0;
	//@ ensures \result >= 0;
	//@ ensures (\forall int i; 0 <= i && i < 32 && i % 2 == 0; (((\result >> i) & 1) == ((num >> i) & 1)));
	//@ ensures (\forall int i; 0 <= i && i < 32 && i % 2 == 1 && (num >> i) != 0; (((\result >> i) & 1) == 1));
	public static int evenBitSetNumber(int num) {
		int result = 0;
		int end = 0;
		int sum = num;
		//@ maintaining 0 <= result && result <= 32;
		//@ maintaining sum == (num >> result);
		//@ maintaining (\forall int i; 0 <= i && i < result; (i % 2 == 1) <==> (((end >> i) & 1) == 1));
		//@ decreases sum;
		while (sum > 0) {
			if (result % 2 == 1) {
				end |= (1 << result);
			}
			result++;
			sum >>= 1;
		}
		return (num | end);
	}
}