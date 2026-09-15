import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

/*@ spec_public @*/
class FindEvenPair {

    //@ ensures arr == null ==> \result == -1;
    //@ ensures arr != null && arr.length == 1 ==> \result == 0;
    //@ ensures arr != null && arr.length == 0 ==> \result == 0;
    //@ ensures arr != null ==> (\forall int k; 0 <= k && k < arr.length; arr[k] == \old(arr[k]));
    //@ ensures arr != null ==> 0 <= \result && \result <= (arr.length * (arr.length - 1)) / 2;
    /*@ spec_public @*/
	public static int findEvenPair(int[] arr, int n) {
		if (arr == null) {
			return -1;
		}
		if (arr.length == 1) {
			return 0;
		}

		int evenPairCount = 0;
        //@ maintaining arr != null;
        //@ maintaining 0 <= i && i <= arr.length;
        //@ maintaining 0 <= evenPairCount && evenPairCount <= (arr.length * (arr.length - 1)) / 2;
        //@ maintaining (\forall int k; 0 <= k && k < arr.length; arr[k] == \old(arr[k]));
        //@ decreases arr.length - i;
		for (int i = 0; i < arr.length; i++) {
            //@ maintaining i + 1 <= c && c <= arr.length;
            //@ maintaining 0 <= evenPairCount && evenPairCount <= (arr.length * (arr.length - 1)) / 2;
            //@ maintaining (\forall int k; 0 <= k && k < arr.length; arr[k] == \old(arr[k]));
            //@ decreases arr.length - c;
			for (int c = i + 1; c < arr.length; c++) {
				int even = arr[i];
				int odd = arr[c];
				int z = even ^ odd;
				if ((z & 1) == 0) {
					evenPairCount++;
				}
			}
		}
		return evenPairCount;
	}
}