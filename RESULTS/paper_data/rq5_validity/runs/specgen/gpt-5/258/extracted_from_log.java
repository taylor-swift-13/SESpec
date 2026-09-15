import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindFixedPoint {

    //@ requires i != null;
    //@ requires 0 <= array && array <= i.length;
    //@ requires (\forall int k; 0 <= k && k + 1 < array; i[k] < i[k+1]);
    //@ assignable \nothing;
    //@ ensures (0 <= \result && \result < array) ==> i[\result] == \result;
    //@ ensures (\result == -1) ==> (\forall int k; 0 <= k && k < array; i[k] != k);
	public static int findFixedPoint(int[] i, int array) {
		int ret = 0;
		int stop = array - 1;
		//@ maintaining 0 <= ret && ret <= array;
		//@ maintaining -1 <= stop && stop < array;
		//@ maintaining ret <= stop + 1;
		//@ maintaining (\forall int k; 0 <= k && k < ret; i[k] < k);
		//@ maintaining (\forall int k; stop < k && k < array; i[k] > k);
		//@ decreases stop - ret + 1;
		//@ loop_assignable \nothing;
		while (ret <= stop) {
			int cur = ret + (stop - ret) / 2;
			if (i[cur] == cur) {
				return cur;
			} else if (i[cur] < cur) {
				ret = cur + 1;
			} else {
				stop = cur - 1;
			}
		}
		return -1;
	}
}