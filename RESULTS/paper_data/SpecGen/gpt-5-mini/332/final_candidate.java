import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class ComputeLastDigit {

    /*@ public normal_behavior
      @   ensures c <= num ==> \result == 1;
      @   ensures c - num >= 5 ==> \result == 0;
      @   ensures c > num && c - num < 5 ==> \result == (\product int v; num+1 <= v && v <= c; (v % 10)) % 10;
      @   ensures 0 <= \result && \result <= 9;
      @*/
	public static int computeLastDigit(int num, int c) {
		int result = 1;
		if (num == c) {
			return 1;
		} else if ((c - num) >= 5) {
			return 0;
		} else {
 
 
 
 
			  @*/
			for (int var = num + 1; var < c + 1; var++) {
				result = (result * (var % 10)) % 10;
			}
			return result % 10;
		}
	}
}
