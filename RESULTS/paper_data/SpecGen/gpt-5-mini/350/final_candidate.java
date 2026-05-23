import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class EvenBitToggleNumber {

	/*@
	  @ requires num >= 0;
	  @ 
	  @ // For every bit position i: if i is an even position and i is within
	  @ // the bit-length of num (i.e. (num >> i) != 0), then the i-th bit of
	  @ // the result is the flip of the i-th bit of num. For positions that
	  @ // are outside the bit-length of num or are odd positions, the i-th
	  @ // bit remains the same.
	  @ ensures (\forall int i; 0 <= i && ((num >> i) != 0) && (i % 2 == 0)
	  @             ; (((\result >> i) & 1) == 1 - ((num >> i) & 1)));
	  @ ensures (\forall int i; 0 <= i && (!((num >> i) != 0) || (i % 2 != 0))
	  @             ; (((\result >> i) & 1) == ((num >> i) & 1)));
	  @*/
	public static int evenBitToggleNumber(int num) {
		int result = 0;
		int ret = 0;
		int total = num;
		/*@
		  @ // total is the remaining higher-order bits of num after ret shifts
		  @ maintaining total == (num >> ret);
		  @ // result has 1-bits at the even positions processed so far
		  @ maintaining result == (\sum int i; 0 <= i && i < ret && i % 2 == 0; 1 << i);
		  @ maintaining ret >= 0;
		  @ decreases total;
		  @*/
		while (total > 0) {
			if (ret % 2 == 0) {
				result = result | (1 << ret);
			}
			ret++;
			total >>= 1;
		}
		return num ^ result;
	}
}