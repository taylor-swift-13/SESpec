import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindOddPair {

	/*@ spec_public @*/
	/*@
	  @ requires arr != null;
	  @ assignable \nothing;
	  @
	  @ // Result equals the number of index pairs (i,j) with 0 <= i < j < arr.length
	  @ // such that ((arr[i] ^ arr[j]) % 2) == 1, exactly as checked in the code.
	  @ ensures \result == (
	  @   \sum int i; 0 <= i && i < arr.length;
	  @     (\sum int j; i + 1 <= j && j < arr.length;
	  @        (((arr[i] ^ arr[j]) % 2) == 1 ? 1 : 0)))
	  @ ;
	  @ ensures \result >= 0;
	  @*/
	public static int findOddPair(int[] arr, int n) {
		int found = 0;
		int offset = arr.length;
		/*@
		  @ maintaining 0 <= c && c <= offset;
		  @ maintaining offset == arr.length;
		  @ maintaining found == (
		  @   \sum int i; 0 <= i && i < c;
		  @     (\sum int j; i + 1 <= j && j < offset;
		  @        (((arr[i] ^ arr[j]) % 2) == 1 ? 1 : 0)))
		  @ ;
		  @ decreases offset - c;
		  @*/
		for (int c = 0; c < offset; c++) {
			/*@
			  @ maintaining 0 <= c && c < offset;
			  @ maintaining c + 1 <= index && index <= offset;
			  @ maintaining offset == arr.length;
			  @ maintaining found == (
			  @   \sum int i; 0 <= i && i < c;
			  @     (\sum int j; i + 1 <= j && j < offset;
			  @        (((arr[i] ^ arr[j]) % 2) == 1 ? 1 : 0)))
			  @   + (\sum int j; c + 1 <= j && j < index;
			  @        (((arr[c] ^ arr[j]) % 2) == 1 ? 1 : 0)));
			  @ decreases offset - index;
			  @*/
			for (int index = c + 1; index < offset; index++) {
				if ((arr[c] ^ arr[index]) % 2 == 1) {
					found++;
				}
			}
		}
		return found;
	}
}