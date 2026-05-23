import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindNthDigit {

    /*@ requires b > 0;
      @ requires r >= 0;
      @ requires num >= 0;
      @ assignable \nothing;
      @ ensures \old(r) == 0 ==> \result == 0;
      @ ensures \old(r) == 1 ==> \result == (10 * \old(num)) / \old(b);
      @ ensures \old(r) >= 2 ==> 0 <= \result && \result < 10;
      @*/
	public static int findNthDigit(int num, int b, int r) {
		int result = 0;
		/*@ maintaining b > 0 && r >= 0 && num >= 0;
		  @ maintaining (r < \old(r)) ==> (0 <= num && num < b);
          @ maintaining (\old(r) >= 2 && r <= \old(r) - 1) ==> (0 <= result && result < 10);
		  @ decreases r;
		  @*/
		while (r > 0) {
			r -= 1;
			num *= 10;
			result = num / b;
			num %= b;
		}
		return result;
	}
}