import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class EvenBitToggleNumber {

	//@ requires num >= 0;
	//@ ensures \result == (num ^ ((num == 0) ? 0 : (((1 << ((32 - Integer.numberOfLeadingZeros(num) + 1) / 2) * 2)) - 1) & 0x55555555));
	public static int evenBitToggleNumber(int num) {
		int result = 0;
		int ret = 0;
		int total = num;
		//@ maintaining total >= 0;
		//@ maintaining 0 <= ret;
		//@ maintaining total == (num >> ret);
		//@ maintaining (result & ~0x55555555) == 0;
		//@ maintaining (\forall int k; 0 <= k && k < ret; (k % 2 == 0) ==> ((result & (1 << k)) != 0));
		//@ decreases total;
		while (total > 0) {
			if (ret % 2 == 0) {
				result = result | (1 << ret);
			}
			ret++;
			total >>= 1;
		}
		return num ^ result;
	}
}