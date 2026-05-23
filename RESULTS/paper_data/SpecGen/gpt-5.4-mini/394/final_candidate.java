import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class LastTwoDigits {

	//@ requires num >= 0;
	//@ ensures \result >= 0 && \result < 100;
 
	//@   (\product int k; 1 <= k && k <= num; k)
	//@ ) % 100);
	public static int lastTwoDigits(int num) {
		int ret = 1;
 
		//@ maintaining ret >= 1;
		//@ maintaining 1 <= loop && loop <= num + 1;
		//@ decreases num - loop + 1;
		for (int loop = 1; loop <= num; loop++) {
			ret *= loop;
		}
		int result = (int) (ret % 100);
		return result;
	}
}
