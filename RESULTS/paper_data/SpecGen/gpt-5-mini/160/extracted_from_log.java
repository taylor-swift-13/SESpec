import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FirstMissingPositive {

	/*@ 
	  @ requires positions != null;
	  @ requires array >= 0;
	  @ requires array <= positions.length;
	  @ 
	  @ ensures 1 <= \result && \result <= array + 1;
	  @ ensures (\forall int i; 0 <= i && i < \result-1; positions[i] == i+1);
	  @ ensures (\result <= array) ==> positions[\result-1] != \result;
	  @*/
	public static int firstMissingPositive(int[] positions, int array) {
		int ret = 0;
		/*@ 
		  @ maintaining 0 <= ret && ret <= array;
		  @ maintaining positions != null && array <= positions.length;
		  @ maintaining (\forall int i; 0 <= i && i < ret; positions[i] == i+1 || positions[i] <= 0 || positions[i] > array);
		  @*/
		while (ret < array) {
			if (positions[ret] <= 0 || positions[ret] > array
					|| positions[ret] == ret + 1) {
				ret++;
			} else {
				int index = positions[ret];
				positions[ret] = positions[index - 1];
				positions[index - 1] = index;
			}
		}
		/*@ 
		  @ maintaining 0 <= ret && ret <= array;
		  @ maintaining (\forall int i; 0 <= i && i < ret; positions[i] == i+1);
		  @*/
		for (ret = 0; ret < array; ret++) {
			if (positions[ret] != ret + 1) {
				return ret + 1;
			}
		}
		return array + 1;
	}
}