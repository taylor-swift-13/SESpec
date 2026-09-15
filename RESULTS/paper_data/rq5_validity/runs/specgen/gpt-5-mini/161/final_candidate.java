import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FirstMissingPositive {

	/*@ 
	  @ requires positions != null;
	  @ requires 0 <= array && array <= positions.length;
	  @ ensures 1 <= \result && \result <= array + 1;
 
 
	  @*/
	public static int firstMissingPositive(int[] positions, int array) {
		int ret = 0;
		/*@ 
		  @ maintaining 0 <= ret && ret <= array;
 
 
		  @*/
		while (ret < array) {
			if (positions[ret] <= 0 || positions[ret] > array
					|| positions[ret] == ret + 1) {
				ret++;
			} else {
				int j = positions[ret];
				positions[ret] = positions[j - 1];
				positions[j - 1] = j;
			}
		}
		/*@ 
		  @ maintaining 0 <= ret && ret <= array;
		  @ maintaining (\forall int i; 0 <= i && i < ret; positions[i] == i + 1);
		  @ decreases array - ret;
		  @*/
		for (ret = 0; ret < array; ret++) {
			if (positions[ret] != ret + 1) {
				return ret + 1;
			}
		}
		return array + 1;
	}
}
