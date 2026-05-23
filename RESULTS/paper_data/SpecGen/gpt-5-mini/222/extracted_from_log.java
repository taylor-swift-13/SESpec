import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindOddPair {

	/*@ 
	  @ requires arr != null;
	  @ requires 0 <= n;
 
	  @*/
	public static int findOddPair(int[] arr, int n) {
		int result = 0;
		int offset = arr.length;
		/*@ 
		  @ maintaining 0 <= index && index <= offset;
		  @ maintaining 0 <= result;
 
		  @ decreases offset - index;
		  @*/
		for (int index = 0; index < offset; index++) {
			/*@ 
 
 
 
			  @                    + (\num_of int j; index+1 <= j && j < c; ((arr[index] ^ arr[j]) % 2 == 1));
			  @ decreases offset - c;
			  @*/
			for (int c = index + 1; c < offset; c++) {
				if ((arr[index] ^ arr[c]) % 2 == 1) {
					result++;
				}
			}
		}
		return result;
	}
}