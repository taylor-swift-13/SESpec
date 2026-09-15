import java.io.*;
import java.lang.*;
import java.util.*;

class FindLastOccurrence {

    /*@ public normal_behavior
      @   requires arr != null;
      @   requires (\forall int p; 0 <= p && p + 1 < arr.length; arr[p] <= arr[p+1]);
      @   // result is either -1 or a valid index of the last occurrence
      @   ensures (\result == -1) || (0 <= \result && \result < arr.length &&
      @            arr[\result] == array &&
      @            (\result == arr.length - 1 || arr[\result + 1] != array));
      @*/
	public static int findLastOccurrence(int[] arr, int array) {
		int i = 0;
		int hi = arr.length - 1;
		int end = 0;
		/*@ maintaining 0 <= i && i <= arr.length;
		  @ maintaining -1 <= hi && hi < arr.length;
		  @ maintaining i <= hi + 1;
		  @ decreases hi - i + 1;
		  @*/
		while (i <= hi) {
			end = (i + hi) / 2;
			if (arr[end] == array) {
				if (end == arr.length - 1
						|| arr[end + 1] != array) {
					return end;
				} else {
					i = end + 1;
				}
			} else if (arr[end] < array) {
				i = end + 1;
			} else {
				hi = end - 1;
			}
		}
		return -1;
	}
}