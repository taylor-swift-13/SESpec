import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindOddPair {

	//@ requires arr != null;
	//@ ensures 0 <= \result;
	//@ ensures \result <= arr.length * (arr.length - 1) / 2;
	//@ ensures (\forall int i; 0 <= i && i < arr.length; arr[i] == \old(arr[i]));
	public static int findOddPair(int[] arr, int n) {
		int result = 0;
		int offset = arr.length;
		//@ maintaining 0 < result && result < offset * (offset - 1) / 2;  
		//@ maintaining 0 <= c && c <= offset;
		//@ maintaining offset == arr.length;
		//@ maintaining (\forall int ii; 0 <= ii && ii < offset; arr[ii] == \old(arr[ii]));
		//@ decreases offset - c;
		for (int c = 0; c < offset; c++) {
			//@ maintaining 0 <= result && result <= offset * (offset - 1) / 2;
			//@ maintaining offset == arr.length;
			//@ maintaining c >= 0 && c < offset;
			//@ maintaining c+1 <= index && index <= offset;
			//@ maintaining (\forall int ii; 0 <= ii && ii < offset; arr[ii] == \old(arr[ii]));
			//@ decreases offset - index;
			for (int index = c + 1; index < offset; index++) {
				if ((arr[c] ^ arr[index]) % 2 == 1) {
					result++;
				}
			}
		}
		return result;
	}
}