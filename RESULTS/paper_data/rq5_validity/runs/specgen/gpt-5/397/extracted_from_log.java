import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class EvenPowerSum {

	//@ requires 0 <= p && p <= 50;
	//@ ensures \result == (\sum int k; 1 <= k && k <= p; ((2*k)*(2*k)*(2*k)*(2*k)));
	/*@ spec_public @*/ public static int evenPowerSum(int p) {
		int even = 0;
		//@ maintaining 1 <= c && c <= p + 1;
		//@ maintaining even == (\sum int k; 1 <= k && k < c; ((2*k)*(2*k)*(2*k)*(2*k)));
		//@ decreases p - c + 1;
		for (int c = 1; c <= p; c++) {
			int tmp = 2 * c;
			even = even + (tmp * tmp * tmp * tmp);
		}
		return even;
	}
}