import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class EvenBitToggleNumber {

	//@ requires number >= 0;
	//@ ensures \result == (number ^ 0);
	public static int evenBitToggleNumber(int number) {
		int i = 0;
		int ret = 0;
		int total = number;
		//@ maintaining total >= 0;
		//@ maintaining ret >= 0;
		//@ maintaining i >= 0;
		//@ maintaining total <= number;
		//@ decreases total;
		while (total > 0) {
			if (ret % 2 == 0) {
				i = i | (1 << ret);
			}
			ret++;
			total >>= 1;
		}
		return number ^ i;
	}
}