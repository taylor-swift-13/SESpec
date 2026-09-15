import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class LargestPos {

	/*@ requires positions != null;
	  @ ensures \result >= 0;
	  @ ensures (\forall int i; 0 <= i && i < positions.length; positions[i] <= \result || positions[i] <= 0);
 
	  @*/
	public static int largestPos(int[] positions) {
		int result = 0;
		/*@ maintaining 0 <= index && index <= positions.length;
		  @ maintaining result >= 0;
		  @ maintaining (\forall int j; 0 <= j && j < index; positions[j] <= result || positions[j] <= 0);
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
