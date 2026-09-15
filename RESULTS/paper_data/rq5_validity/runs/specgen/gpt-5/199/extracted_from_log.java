import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class CatalanNumber {

    /*@ spec_public pure @*/
    /*@ 
      @ requires 0 <= number && number <= 19;
      @ ensures \result == (number == 0 
      @                      ? 1 
      @                      : (\sum int i; 0 <= i && i < number; catalanNumber(i) * catalanNumber(number - 1 - i)));
      @*/
	public static int catalanNumber(int number) {
		int[] arr = new int[number + 1];
		arr[0] = 1;
        /*@ 
          @ maintaining arr.length == number + 1
          @   && 1 <= c && c <= number
          @   && arr[0] == 1
          @   && (\forall int k; 0 <= k && k < c;
          @          (k == 0 
          @            ? arr[k] == 1 
          @            : arr[k] == (\sum int i; 0 <= i && i < k; arr[i] * arr[k - 1 - i])))
          @   && (\forall int k; 0 <= k && k < c; arr[k] >= 0);
          @ decreases number - c + 1;
          @*/
		for (int c = 1; c <= number; c++) {
			arr[c] = 0;
            /*@ 
              @ maintaining 0 <= n && n <= c
              @   && arr.length == number + 1
              @   && (\forall int k; 0 <= k && k < c;
              @          (k == 0 
              @            ? arr[k] == 1 
              @            : arr[k] == (\sum int i; 0 <= i && i < k; arr[i] * arr[k - 1 - i])))
              @   && arr[c] == (\sum int i; 0 <= i && i < n; arr[i] * arr[c - 1 - i])
              @   && arr[c] >= 0;
              @ decreases c - n;
              @*/
			for (int n = 0; n < c; n++) {
				arr[c] += arr[n]
						* arr[c - n - 1];
			}
		}
		return arr[number];
	}
}