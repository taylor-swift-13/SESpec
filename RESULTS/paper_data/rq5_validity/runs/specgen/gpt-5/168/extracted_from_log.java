import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindRotationCount {

    /*@ spec_public @*/
    /*@ requires arr != null;
      @ requires arr.length > 0 ==>
      @          (\exists int rot; 0 <= rot && rot < arr.length;
      @              (\forall int t; 0 <= t && t < arr.length - 1;
      @                  arr[(rot + t) % arr.length] < arr[(rot + t + 1) % arr.length]));
      @ ensures arr.length == 0 ==> \result == 0;
      @ ensures arr.length > 0 ==> 0 <= \result && \result < arr.length;
      @ ensures (\forall int i; 0 <= i && i < arr.length; arr[i] == \old(arr[i]));
      @ ensures arr.length > 0 ==> (\forall int i; 0 <= i && i < arr.length; arr[\result] <= arr[i]);
      @ ensures arr.length > 0 && \result == 0 ==> (\forall int i; 0 <= i && i < arr.length - 1; arr[i] <= arr[i+1]);
      @ ensures arr.length > 0 && \result > 0 ==> arr[\result] < arr[\result - 1];
      @ ensures arr.length > 0 ==> (\forall int t; 0 <= t && t < arr.length - 1;
      @                                 arr[(\result + t) % arr.length] <= arr[(\result + t + 1) % arr.length]);
      @*/
	public static int findRotationCount(int[] arr) {
		int ret = 0;
		int count = arr.length - 1;
		//@ maintaining 0 <= ret && ret <= count + 1 && 0 <= count && count < arr.length;
		//@ maintaining (\forall int p; 1 <= p && p < arr.length && arr[p] < arr[p-1]; ret <= p && p <= count);
		//@ decreases count - ret + 1;
		while (ret <= count) {
			int r = ret + (count - ret) / 2;
			if (r < count
					&& arr[r] > arr[r + 1]) {
				return r + 1;
			} else if (r > ret
					&& arr[r] < arr[r - 1]) {
				return r;
			}
			if (arr[r] >= arr[ret]) {
				ret = r + 1;
			} else {
				count = r - 1;
			}
		}
		return 0;
	}
}