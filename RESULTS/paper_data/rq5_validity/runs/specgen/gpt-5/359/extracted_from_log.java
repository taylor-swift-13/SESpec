import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class AverageOdd {

    //@ requires size >= 1;
    //@ ensures \result == (\sum int i; 1 <= i && i <= size && i % 2 != 0; i) / (\sum int i; 1 <= i && i <= size && i % 2 != 0; 1);
    //@ ensures \result == (1 + ((size % 2 == 1) ? size : (size - 1))) / 2;
    //@ ensures 1 <= \result && \result <= size;
	public static int averageOdd(int size) {
		int ret = 0;
		int total = 0;
        //@ maintaining 1 <= c && c <= size + 1;
        //@ maintaining ret == (\sum int i; 1 <= i && i < c && i % 2 != 0; i);
        //@ maintaining total == (\sum int i; 1 <= i && i < c && i % 2 != 0; 1);
        //@ decreases size - c + 1;
		for (int c = 1; c <= size; c++) {
			if (c % 2 != 0) {
				ret += c;
				total++;
			}
		}
		return ret / total;
	}
}