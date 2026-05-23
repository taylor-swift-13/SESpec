import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class EvenBitSetNumber {

	/*@ requires num >= 0;
	  @ ensures \result >= num;
	  @ ensures (\result & num) == num;
	  @*/
	public static int evenBitSetNumber(int num) {
		int result = 0;
		int end = 0;
		int sum = num;
		/*@ maintaining sum >= 0;
		  @ maintaining result >= 0;
		  @ decreasing sum;
		  @*/
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