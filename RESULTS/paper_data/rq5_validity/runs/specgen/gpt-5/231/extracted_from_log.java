import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class CountPairs {

	//@ requires p != null;
	//@ ensures array == \old(array);
	//@ ensures (\forall int i; 0 <= i && i < p.length; p[i] == \old(p[i]));
	//@ ensures 0 <= \result && \result <= (p.length * (p.length - 1)) / 2;
	//@ ensures (\forall int i; 0 <= i && i < p.length - 1; (\forall int j; i + 1 <= j && j < p.length; p[i] == p[j])) ==> \result == 0;
	//@ ensures (\forall int i; 0 <= i && i < p.length - 1; (\forall int j; i + 1 <= j && j < p.length; p[i] != p[j])) ==> \result == (p.length * (p.length - 1)) / 2;
	public static int countPairs(int[] p, int array) {
		int count = 0;
		int total = p.length;
		//@ maintaining total == p.length;
		//@ maintaining 0 <= index && index <= total - 1;
		//@ maintaining 0 <= count && count <= (p.length * (p.length - 1)) / 2;
		//@ decreases total - 1 - index;
		for (int index = 0; index < total - 1; index++) {
			//@ maintaining index + 1 <= c && c <= total;
			//@ maintaining total == p.length;
			//@ maintaining 0 <= count && count <= (p.length * (p.length - 1)) / 2;
			//@ decreases total - c;
			for (int c = index + 1; c < total; c++) {
				if (p[index] != p[c]) {
					count++;
				}
			}
		}
		return count;
	}
}