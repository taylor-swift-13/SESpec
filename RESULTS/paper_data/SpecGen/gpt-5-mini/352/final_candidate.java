import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class EvenBitToggleNumber {

	/*@ public normal_behavior
	  @   requires number >= 0;
	  @   // For every bit position i in the 32-bit int range:
	  @   // - if the loop processes position i (i.e. i < bit-length of number) and i is even,
	  @   //   then the i-th bit of the returned value is the toggle of the i-th bit of number.
	  @   // - otherwise the i-th bit of the returned value equals the i-th bit of number.
	  @   ensures (\forall int i; 0 <= i && i < 32;
	  @              ((number >>> i) != 0 && i % 2 == 0)
	  @                ==> (((\result >>> i) & 1) == 1 - ((number >>> i) & 1))
	  @           );
	  @   ensures (\forall int i; 0 <= i && i < 32;
	  @              !((number >>> i) != 0 && i % 2 == 0)
	  @                ==> (((\result >>> i) & 1) == ((number >>> i) & 1))
	  @           );
	  @*/
	public static int evenBitToggleNumber(int number) {
		int result = 0;
		int ret = 0;
		int total = number;
		//@ maintaining number >= 0;
		//@ maintaining ret >= 0;
		//@ maintaining total >= 0;
		//@ maintaining total == (number >> ret);
		//@ maintaining (\forall int i; 0 <= i && i < ret; (i % 2 == 0) ==> (((result >>> i) & 1) == 1));
		//@ maintaining (\forall int i; 0 <= i && i < ret; (i % 2 == 1) ==> (((result >>> i) & 1) == 0));
		//@ decreases total;
		while (total > 0) {
			if (ret % 2 == 0) {
				result = result | (1 << ret);
			}
			ret++;
			total >>= 1;
		}
		return number ^ result;
	}
}