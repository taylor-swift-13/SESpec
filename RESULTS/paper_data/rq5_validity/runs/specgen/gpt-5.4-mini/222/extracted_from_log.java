import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindOddPair {

	//@ requires arr != null;
	//@ requires n >= 0;
	//@ ensures \result >= 0;
	//@ ensures \result == (\num_of int i, int j; 0 <= i && i < arr.length && 0 <= j && j < arr.length && i < j && ((arr[i] ^ arr[j]) % 2 == 1); 1);
	public static int findOddPair(int[] arr, int n) {
		int result = 0;
		int offset = arr.length;
		//@ maintaining 0 <= index && index <= offset;
		//@ maintaining 0 <= result;
		//@ maintaining offset == arr.length;
		//@ maintaining (\num_of int i, int j; 0 <= i && i < index && 0 <= j && j < offset && i < j && ((arr[i] ^ arr[j]) % 2 == 1); 1) == result;
		//@ decreases offset - index;
		for (int index = 0; index < offset; index++) {
			//@ maintaining 0 <= c && c <= offset;
			//@ maintaining index + 1 <= c && c <= offset;
			//@ maintaining 0 <= result;
			//@ maintaining (\num_of int i, int j; 0 <= i && i < index && 0 <= j && j < offset && i < j && ((arr[i] ^ arr[j]) % 2 == 1); 1)
			//@          + (\num_of int j; index + 1 <= j && j < c && ((arr[index] ^ arr[j]) % 2 == 1); 1) == result;
			//@ decreases offset - c;
			for (int c = index + 1; c < offset; c++) {
				if ((arr[index] ^ arr[c]) % 2 == 1) {
					result++;
				}
			}
		}
		return result;
	}
}