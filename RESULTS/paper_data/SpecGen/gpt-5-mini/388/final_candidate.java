import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindNthDigit {

	//@ requires c > 0;
	//@ requires num >= 0;
	//@ requires r >= 0;
	//@ ensures 0 <= \result && \result <= 9;
 
	public static int findNthDigit(int num, int c, int r) {
		int result = 0;
		//@ maintaining r >= 0;
		//@ maintaining 0 <= num;
		//@ maintaining 0 < result && result < 9;  
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
