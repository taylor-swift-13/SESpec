import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class LargestPos {

	//@ requires positions != null;
	//@ ensures \result >= 0;
	//@ ensures (\forall int i; 0 <= i && i < positions.length; positions[i] > 0 ==> positions[i] <= \result);
	//@ ensures (\result > 0) ==> (\exists int i; 0 <= i && i < positions.length && positions[i] == \result);
	//@ ensures \result == 0 <==> (\forall int i; 0 <= i && i < positions.length; positions[i] <= 0);
	public static int largestPos(int[] positions) {
		int largest = 0;
		//@ maintaining 0 <= largest;
		//@ maintaining 0 <= index && index <= positions.length;
		//@ maintaining (\forall int j; 0 <= j && j < index; positions[j] > 0 ==> positions[j] <= largest);
		//@ maintaining (largest == 0) || (\exists int k; 0 <= k && k < index && positions[k] == largest);
		//@ decreases positions.length - index;
		for (int index = 0; index < positions.length; index++) {
			if (positions[index] > 0 && positions[index] > largest) {
				largest = positions[index];
			}
		}
		return largest;
	}
}