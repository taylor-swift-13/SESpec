import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class EvenBinomialCoeffSum {

	//@ requires seed >= 0 && seed <= 31;
	//@ ensures \result == (seed == 0 ? 1 : (1 << (seed - 1)));
	//@ ensures \result > 0;
	public static int evenBinomialCoeffSum(int seed) {
		int result = 0;
		int[] temp = new int[seed + 1];
		temp[0] = 1;
		//@ maintaining 1 <= d && d <= seed + 1;
		//@ maintaining temp.length == seed + 1;
		//@ maintaining temp[0] == 1;
		//@ maintaining (\forall int i; 1 <= i && i < d; temp[i] == (1 << (i - 1)));
		//@ maintaining (\forall int i; d <= i && i < temp.length; temp[i] == 0);
		//@ decreases seed - d + 1;
		for (int d = 1; d <= seed; d++) {
			//@ maintaining 0 <= c && c <= d;
			//@ maintaining temp.length == seed + 1;
			//@ maintaining temp[0] == 1;
			//@ maintaining (\forall int i; 1 <= i && i < d; temp[i] == (1 << (i - 1)));
			//@ maintaining (\forall int i; d < i && i < temp.length; temp[i] == 0);
			//@ maintaining temp[d] == (c == 0 ? 0 : (1 << (c - 1)));
			//@ decreases d - c;
			for (int c = 0; c < d; c++) {
				temp[d] = temp[d] + temp[c];
			}
		}
		return temp[seed];
	}
}