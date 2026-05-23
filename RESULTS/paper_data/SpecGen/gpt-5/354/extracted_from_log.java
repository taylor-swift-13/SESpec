import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class EvenBitSetNumber {

	//@ ensures num <= 0 ==> \result == num;
	//@ ensures num > 0 ==> (\forall int i; 0 <= i && i < 32; ((i % 2 == 1 && (num >> i) > 0) ==> ((\result & (1 << i)) != 0)));
	//@ ensures (\forall int i; 0 <= i && i < 32; (i % 2 == 0) ==> ((\result & (1 << i)) == (num & (1 << i))));
	//@ ensures num > 0 ==> (\forall int i; 0 <= i && i < 32; ((num >> i) == 0) ==> ((\result & (1 << i)) == (num & (1 << i))));
	public static int evenBitSetNumber(int num) {
		int even = 0;
		int result = 0;
		int sum = num;
		//@ maintaining 0 <= even && even <= 32;
		//@ maintaining sum == (num >> even);
		//@ maintaining (\forall int j; 0 <= j && j < even && j < 32; (j % 2 == 1) ==> ((result & (1 << j)) != 0));
		//@ maintaining (\forall int j; 0 <= j && j < even && j < 32; (j % 2 == 0) ==> ((result & (1 << j)) == 0));
		//@ maintaining (\forall int j; even <= j && j < 32; ((result & (1 << j)) == 0));
		//@ decreases sum;
		while (sum > 0) {
			if (even % 2 == 1) {
				result |= (1 << even);
			}
			even++;
			sum >>= 1;
		}
		return (num | result);
	}
}