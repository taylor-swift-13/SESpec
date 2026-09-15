import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class LargestPos {

    //@ requires positions != null;
    //@ ensures \result >= 0;
    //@ ensures (\forall int i; 0 <= i && i < positions.length; positions[i] > 0 ==> positions[i] <= \result);
    //@ ensures (\exists int i; 0 <= i && i < positions.length; positions[i] > 0) ==> (\result > 0 && (\exists int j; 0 <= j && j < positions.length; positions[j] == \result));
    //@ ensures !(\exists int i; 0 <= i && i < positions.length; positions[i] > 0) ==> \result == 0;
	public static int largestPos(int[] positions) {
		int largest = 0;
        //@ maintaining 0 <= index && index <= positions.length;
        //@ maintaining largest >= 0;
        //@ maintaining (\forall int k; 0 <= k && k < index; positions[k] > 0 ==> positions[k] <= largest);
        //@ maintaining (\exists int k; 0 <= k && k < index; positions[k] > 0) ==> (largest > 0 && (\exists int k2; 0 <= k2 && k2 < index; positions[k2] == largest));
        //@ maintaining !(\exists int k; 0 <= k && k < index; positions[k] > 0) ==> largest == 0;
        //@ decreases positions.length - index;
		for (int index = 0; index < positions.length; index++) {
			if (positions[index] > 0 && positions[index] > largest) {
				largest = positions[index];
			}
		}
		return largest;
	}
}