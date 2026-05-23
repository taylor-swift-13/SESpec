import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class CountNo {

    /*@ requires code != 0;
      @ ensures (\result != -1) ==>
      @   (l <= \result && \result <= m
      @    && (\sum int i; l <= i && i <= \result; ((i % code != 0) ? 1 : 0)) == b
      @    && (\forall int t; l <= t && t < \result;
      @          (\sum int i; l <= i && i <= t; ((i % code != 0) ? 1 : 0)) != b));
      @ ensures (\result == -1) ==>
      @   (\forall int t; l <= t && t <= m;
      @        (\sum int i; l <= i && i <= t; ((i % code != 0) ? 1 : 0)) != b);
      @*/
	public static int countNo(int code, int b, int l, int m) {
		int result = 0;
		/*@ maintaining l <= c && c <= m + 1;
		  @ maintaining 0 <= result
		  @   && result == (\sum int i; l <= i && i < c; ((i % code != 0) ? 1 : 0));
		  @ maintaining (\forall int t; l <= t && t < c;
		  @                 (\sum int i; l <= i && i <= t; ((i % code != 0) ? 1 : 0)) != b);
		  @ decreases m - c + 1;
		  @*/
		for (int c = l; c <= m; c++) {
			if (c % code != 0) {
				result++;
			}
			if (result == b) {
				return c;
			}
		}
		return -1;
	}
}