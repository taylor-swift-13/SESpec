import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class EvenBinomialCoeffSum {

	//@ requires seed >= 0;
 
	public static int evenBinomialCoeffSum(int seed) {
		int result = 0;
		int[] temp = new int[seed + 1];
		temp[0] = 1;
		//@ maintaining 1 <= d && d <= seed + 1;
		//@ maintaining temp != null && temp.length == seed + 1;
 
		//@ decreases seed - d + 1;
		for (int d = 1; d <= seed; d++) {
			//@ maintaining 0 <= c && c <= d;
			//@ maintaining 0 <= d && d <= seed;
			//@ maintaining temp != null && temp.length == seed + 1;
			//@ decreases d - c;
			for (int c = 0; c < d; c++) {
				temp[d] = temp[d] + temp[c];
			}
		}
		return temp[seed];
	}
}