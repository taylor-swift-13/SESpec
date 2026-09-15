import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class LastTwoDigits {

	/*@
	  requires num >= 0;
	  ensures 0 <= \result && \result < 100;
	  ensures num == 0 ==> \result == 1;
	  ensures \result == ((\bigint) (\product int i; 1 <= i && i <= num; i)) % 100;
	@*/
	public static int lastTwoDigits(int num) {
		int ret = 1;
		/*@
		  maintaining 1 <= loop && loop <= num + 1;
		  maintaining ret == (\bigint) (\product int i; 1 <= i && i <= loop-1; i);
		  decreases num - loop + 1;
		@*/
		for (int loop = 1; loop <= num; loop++) {
			ret *= loop;
		}
		int remainder = (int) (ret % 100);
		return remainder;
	}
}