import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class LargestPos {

    /*@ public normal_behavior
      @   requires positions != null;
      @   ensures \result >= 0;
      @   // If there is no positive element, result is 0
 
      @   // If result is positive then it is one of the positive elements
 
      @   // If result is positive then it is at least as large as every element
      @   ensures \result > 0 ==> (\forall int i; 0 <= i && i < positions.length; positions[i] <= \result);
      @*/
	public static int largestPos(int[] positions) {
		int result = 0;
		/*@ 
 
 
 
 
		  @             ==> (\exists int j; 0 <= j && j < index; positions[j] == result && positions[j] > 0));
		  @ decreases positions.length - index;
		  @*/
		for (int index = 0; index < positions.length; index++) {
			if (positions[index] > 0 && positions[index] > result) {
				result = positions[index];
			}
		}
		return result;
	}
}
