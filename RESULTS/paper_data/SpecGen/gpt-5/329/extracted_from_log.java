import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class Difference {

    //@ ensures \result == (\sum int j; 1 <= j && j <= diff; j*j*j) - (\sum int j; 1 <= j && j <= diff; j);
    //@ ensures diff <= 0 ==> \result == 0;
	public static int difference(int diff) {
		int ret = 0;
		int max = 0;
        //@ maintaining 1 <= j && j <= diff + 1;
        //@ maintaining ret == (\sum int k; 1 <= k && k < j; k*k*k);
        //@ decreases diff - j + 1;
		for (int j = 1; j <= diff; j++) {
			ret += j * j * j;
		}
        //@ maintaining 1 <= j && j <= diff + 1;
        //@ maintaining max == (\sum int k; 1 <= k && k < j; k);
        //@ maintaining ret == (\sum int k; 1 <= k && k <= diff; k*k*k);
        //@ decreases diff - j + 1;
		for (int j = 1; j <= diff; j++) {
			max += j;
		}
		return ret - max;
	}
}