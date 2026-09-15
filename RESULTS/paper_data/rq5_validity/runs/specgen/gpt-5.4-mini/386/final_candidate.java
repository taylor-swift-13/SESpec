import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindNthDigit {

	//@ requires b > 0 && r >= 0;
 
 
	public static int findNthDigit(int num, int b, int r) {
		int result = 0;
		//@ maintaining r >= 0;
 
		//@ decreases r;
		while (r > 0) {
			r -= 1;
			num *= 10;
			result = num / b;
			num %= b;
		}
		return result;
	}
}
