import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class LargestPos {

	//@ requires positions != null;
	//@ ensures \result >= 0;
	//@ ensures (\forall int i; 0 <= i && i < positions.length; positions[i] > 0 ==> \result >= positions[i]);
	//@ ensures (\exists int i; 0 <= i && i < positions.length; positions[i] > 0) ==> (\exists int i; 0 <= i && i < positions.length; positions[i] == \result && positions[i] > 0);
	//@ ensures !(\exists int i; 0 <= i && i < positions.length; positions[i] > 0) ==> \result == 0;
	//@ ensures (\forall int i; 0 <= i && i < positions.length; positions[i] == \old(positions[i]));
	public static int largestPos(int[] positions) {
		int largest = 0;
		//@ maintaining 0 <= count && count <= positions.length;
		//@ maintaining largest >= 0;
		//@ maintaining (\forall int i; 0 <= i && i < count; positions[i] > 0 ==> positions[i] <= largest);
		//@ maintaining (!(\exists int i; 0 <= i && i < count; positions[i] > 0) ==> largest == 0);
		//@ maintaining ((\exists int i; 0 <= i && i < count; positions[i] > 0) ==> (\exists int i; 0 <= i && i < count; positions[i] == largest && positions[i] > 0));
		//@ decreases positions.length - count;
		for (int count = 0; count < positions.length; count++) {
			if (positions[count] > 0 && positions[count] > largest) {
				largest = positions[count];
			}
		}
		return largest;
	}
}