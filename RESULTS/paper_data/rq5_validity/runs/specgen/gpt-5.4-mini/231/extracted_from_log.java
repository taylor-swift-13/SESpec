import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class CountPairs {

	//@ requires p != null;
 
 
	public static int countPairs(int[] p, int array) {
		int count = 0;
		int total = p.length;
 
		//@ maintaining 0 <= index && index - 1 <= total - 1;  
		//@ maintaining total == p.length;
		//@ decreases total - index;
		for (int index = 0; index < total - 1; index++) {
			//@ maintaining index + 1 <= c && c <= total;
 
			//@ maintaining (\forall int i; 0 <= i && i < index; (\forall int j; i + 1 <= j && j < total; true));
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