import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class EvenPowerSum {

	//@ requires p >= 0;
	//@ requires (\sum int i; 1 <= i && i <= p; 16*i*i*i*i) <= Integer.MAX_VALUE;
	//@ ensures \result == (\sum int i; 1 <= i && i <= p; 16*i*i*i*i);
	//@ ensures \result >= 0;
	//@ assignable \nothing;
	public static int evenPowerSum(int p) {
		int odd = 0;
		//@ maintaining 1 <= c && c <= p + 1;
		//@ maintaining odd == (\sum int i; 1 <= i && i < c; 16*i*i*i*i);
		//@ maintaining odd >= 0;
		//@ decreases p - c + 1;
		for (int c = 1; c <= p; c++) {
			int tmp = 2 * c;
			odd = odd + (tmp * tmp * tmp * tmp);
		}
		return odd;
	}
}