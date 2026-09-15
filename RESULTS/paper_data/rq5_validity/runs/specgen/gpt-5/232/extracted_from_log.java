import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class CountPairs {

    //@ requires pairs != null;
    //@ ensures (\forall int k; 0 <= k && k < pairs.length; pairs[k] == \old(pairs[k]));
    //@ ensures \result == (\sum int i; 0 <= i && i < pairs.length; (\sum int j; i + 1 <= j && j < pairs.length; (pairs[i] != pairs[j] ? 1 : 0)));
	public static int countPairs(int[] pairs, int array) {
		int count = 0;
		int total = pairs.length;
        //@ maintaining total == pairs.length;
        //@ maintaining 0 <= count;
        //@ maintaining (total <= 1 ==> index == 0) && (total > 1 ==> (0 <= index && index <= total - 1));
        //@ maintaining count == (\sum int i; 0 <= i && i < index; (\sum int j; i + 1 <= j && j < total; (pairs[i] != pairs[j] ? 1 : 0)));
        //@ decreases (total <= 1 ? 0 : (total - 1 - index));
		for (int index = 0; index < total - 1; index++) {
            //@ maintaining index + 1 <= c && c <= total;
            //@ maintaining count == (\sum int i; 0 <= i && i < index; (\sum int j; i + 1 <= j && j < total; (pairs[i] != pairs[j] ? 1 : 0))) + (\sum int j; index + 1 <= j && j < c; (pairs[index] != pairs[j] ? 1 : 0));
            //@ decreases total - c;
			for (int c = index + 1; c < total; c++) {
				if (pairs[index] != pairs[c]) {
					count++;
				}
			}
		}
		return count;
	}
}