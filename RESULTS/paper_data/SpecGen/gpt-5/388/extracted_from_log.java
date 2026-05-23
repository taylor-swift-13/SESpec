import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindNthDigit {

    /*@
      @ requires c != 0;
      @ requires r >= 0;
      @ ensures r == 0;
      @*/
	public static int findNthDigit(int num, int c, int r) {
		int result = 0;
        //@ maintaining r >= 0;
        //@ maintaining c != 0;
        //@ decreases r;
		while (r > 0) {
			r -= 1;
			num *= 10;
			result = num / c;
			num %= c;
		}
		return result;
	}
}