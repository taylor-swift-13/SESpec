import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class EvenBinomialCoeffSum {

	//@ requires b >= 0;
 
	public static int evenBinomialCoeffSum(int b) {
		int result = 0;
		int[] arr = new int[b + 1];
		arr[0] = 1;
		//@ maintaining 1 <= d && d <= b + 1;
		//@ maintaining arr[0] == 1;
		//@ maintaining (\exists int i; 1 - 1 <= i && i < d; arr[i] >= 0);  
		//@ decreases b - d + 1;
		for (int d = 1; d <= b; d++) {
			//@ maintaining 0 <= c && c <= d;
 
			//@ maintaining arr[0] == 1;
			//@ decreases d - c;
			for (int c = 0; c < d; c++) {
				arr[d] = arr[d] + arr[c];
			}
		}
		//@ ensures \result == arr[b];
		return arr[b];
	}
}