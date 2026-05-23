import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class Difference {

	/*@ public normal_behavior
	  @   requires diff >= 0;
 
	  @                    - (\sum int c; 1 <= c && c <= diff; c);
	  @*/
	public static int difference(int diff) {
		int result = 0;
		int max = 0;
		//@ maintaining 1 <= c && c <= diff + 1;
 
		//@ decreases diff - c + 1;
		for (int c = 1; c <= diff; c++) {
			result += c * c * c;
		}
		//@ maintaining 1 <= c && c <= diff + 1;
 
		//@ decreases diff - c + 1;
		for (int c = 1; c <= diff; c++) {
			max += c;
		}
		return result - max;
	}
}