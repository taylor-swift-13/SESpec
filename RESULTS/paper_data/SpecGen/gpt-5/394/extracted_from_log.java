import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class LastTwoDigits {

    //@ requires 0 <= num && num <= 12;
    //@ ensures 0 <= \result && \result < 100;
    //@ ensures (\bigint)\result == ((\product int i; 1 <= i && i <= num; (\bigint)i) % 100);
	public static int lastTwoDigits(int num) {
		int ret = 1;
        //@ maintaining 1 <= loop && loop <= num + 1;
        //@ maintaining (\bigint)ret == (\product int i; 1 <= i && i < loop; (\bigint)i);
        //@ decreases num - loop + 1;
		for (int loop = 1; loop <= num; loop++) {
			ret *= loop;
		}
		int result = (int) (ret % 100);
		return result;
	}
}