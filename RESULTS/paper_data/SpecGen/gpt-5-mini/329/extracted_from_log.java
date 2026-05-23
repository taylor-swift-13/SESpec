import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class Difference {

	//@ requires diff >= 0;
	//@ ensures \result == (\sum int j; 1 <= j && j <= diff; j*j*j) - (\sum int j; 1 <= j && j <= diff; j);
	public static int difference(int diff) {
		int ret = 0;
		int max = 0;
 
		//@ decreasing diff - j + 1;
		for (int j = 1; j <= diff; j++) {
			ret += j * j * j;
		}
		//@ maintaining 1 - 1 <= j && j < diff + 1 && max == (\sum int k; 1 <= k && k < j; k);  
		//@ decreasing diff - j + 1;
		for (int j = 1; j <= diff; j++) {
			max += j;
		}
		return ret - max;
	}
}