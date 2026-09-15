import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindFixedPoint {

	//@ requires 0 <= array && array <= i.length;
	//@ requires (\forall int u, v; 0 <= u && u < v && v < array ==> i[u] < i[v]);
 
	//@ ensures \result != -1 ==> (0 <= \result && \result < array && i[\result] == \result);
	public static int findFixedPoint(int[] i, int array) {
		int ret = 0;
		int stop = array - 1;
		//@ maintaining 0 <= ret && -1 <= stop && stop < array;
		//@ maintaining ret <= stop + 1;
 
 
		//@ decreases stop - ret + 1;
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