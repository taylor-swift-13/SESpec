import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindOddPair {

	//@ requires arr != null;
	//@ requires n >= 0 && n <= arr.length;
	//@ ensures \result >= 0;
	//@ ensures \result == (\sum int c; 0 <= c && c < arr.length;
	//@                    (\sum int index; c + 1 <= index && index < arr.length;
	//@                     (((arr[c] ^ arr[index]) % 2) == 1 ? 1 : 0)));
	public static int findOddPair(int[] arr, int n) {
		int result = 0;
		int offset = arr.length;
 
 
		//@                    (\sum int j; i + 1 <= j && j < offset;
		//@                     (((arr[i] ^ arr[j]) % 2) == 1 ? 1 : 0)));
		//@ decreases offset - c;
		for (int c = 0; c < offset; c++) {
			//@ maintaining c + 1 <= index && index <= offset;
			//@ maintaining result == (\sum int i; 0 <= i && i < c;
			//@                    (\sum int j; i + 1 <= j && j < offset;
			//@                     (((arr[i] ^ arr[j]) % 2) == 1 ? 1 : 0)))
			//@                 + (\sum int j; c + 1 <= j && j < index;
			//@                    (((arr[c] ^ arr[j]) % 2) == 1 ? 1 : 0));
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