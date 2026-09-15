import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FirstMissingPositive {

	//@ requires positions != null;
	//@ requires 0 <= array && array <= positions.length;
	//@ ensures 1 <= \result && \result <= array + 1;
	//@ ensures (\forall int i; 1 - 1 <= i && i <= \result; (\forall int j; 0 <= j && j <= array; positions[j] == i));  
	public static int firstMissingPositive(int[] positions, int array) {
		int ret = 0;
		//@ maintaining 0 <= ret && ret <= array;
		//@ maintaining (\forall int i; 0 <= i && i < ret; positions[i] == i + 1 || positions[i] <= 0 || positions[i] > array);
		//@ decreases array - ret;
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
		//@ maintaining 0 <= ret && ret <= array;
		//@ maintaining (\forall int i; 0 <= i && i < ret; positions[i] == i + 1);
		//@ decreases array - ret;
		for (ret = 0; ret < array; ret++) {
			if (positions[ret] != ret + 1) {
				return ret + 1;
			}
		}
		return array + 1;
	}
}