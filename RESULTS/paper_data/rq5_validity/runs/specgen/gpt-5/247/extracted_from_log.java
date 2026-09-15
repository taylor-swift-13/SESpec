import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class GetInvCount {

	/*@ spec_public @*/
	//@ requires indices != null;
	//@ requires 0 <= num && num <= indices.length;
	//@ ensures \result == (\sum int i; 0 <= i && i < num; (\sum int j; i < j && j < num; (indices[i] > indices[j] ? 1 : 0)));
	//@ ensures 0 <= \result && \result <= (num * (num - 1)) / 2;
	public static int getInvCount(int[] indices, int num) {
		int ret = 0;

		//@ maintaining 0 <= index && index <= num;
		//@ maintaining 0 <= ret && ret <= (num * (num - 1)) / 2;
		//@ maintaining ret == (\sum int i; 0 <= i && i < index; (\sum int j; i < j && j < num; (indices[i] > indices[j] ? 1 : 0)));
		//@ decreases num - index;
		for (int index = 0; index < num; index++) {
			//@ maintaining index + 1 <= c && c <= num;
			//@ maintaining 0 <= ret && ret <= (num * (num - 1)) / 2;
			//@ maintaining ret == (\sum int i; 0 <= i && i < index; (\sum int j; i < j && j < num; (indices[i] > indices[j] ? 1 : 0))) + (\sum int j; index < j && j < c; (indices[index] > indices[j] ? 1 : 0));
			//@ decreases num - c;
			for (int c = index + 1; c < num; c++) {
				if (indices[index] > indices[c]) {
					ret++;
				}
			}
		}
		return ret;
	}
}