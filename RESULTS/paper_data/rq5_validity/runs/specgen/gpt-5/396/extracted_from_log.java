import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class EvenPowerSum {

	/*@ public normal_behavior
	  @   requires p >= 0;
	  @   ensures \result == (\sum int c; 1 <= c && c <= p; (2*c)*(2*c)*(2*c)*(2*c));
	  @   assignable \nothing;
	  @*/
	public static int evenPowerSum(int p) {
		int even = 0;
		//@ maintaining 1 <= c && c <= p + 1;
		//@ maintaining even == (\sum int t; 1 <= t && t < c; (2*t)*(2*t)*(2*t)*(2*t));
		//@ decreases p - c + 1;
		for (int c = 1; c <= p; c++) {
			int count = 2 * c;
			even = even + (count * count * count * count);
		}
		return even;
	}
}