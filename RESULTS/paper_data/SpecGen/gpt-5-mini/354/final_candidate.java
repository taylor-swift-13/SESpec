import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class EvenBitSetNumber {

	/*@ spec_public @*/
	//@ requires num >= 0;
	//@ ensures num == 0 ==> \result == 0;
	//@ ensures num > 0 ==>
	//@   (\exists int L; L >= 1 &&
	//@        (num >> L) == 0 &&
	//@        (\forall int t; 0 <= t && t < L; (num >> t) != 0) &&
	//@        (\forall int i; 0 <= i;
	//@            (i < L ==>
	//@                ( (i % 2 == 1) ==> (((\result >> i) & 1) == 1) &&
	//@                  (i % 2 == 0) ==> (((\result >> i) & 1) == ((num >> i) & 1))
	//@                )
	//@            ) &&
	//@            (i >= L ==> (((\result >> i) & 1) == ((num >> i) & 1)))
	//@        )
	//@   );
	public static int evenBitSetNumber(int num) {
		int even = 0;
		int result = 0;
		int sum = num;
		//@ maintaining sum == (num >> even);
		//@ maintaining 0 <= even;
		//@ maintaining (\forall int i; 0 <= i && i < even ==>
		//@                ( (i % 2 == 1) ==> (((result >> i) & 1) == 1) &&
		//@                  (i % 2 == 0) ==> (((result >> i) & 1) == 0)
		//@                )
		//@           );
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