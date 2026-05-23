import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class EvenBitToggleNumber {

    /*@ spec_public @*/
    /*@
      @ ensures num <= 0 ==> \result == num;
      @ ensures (\forall int p; 0 <= p && p < 32 && (num >> p) > 0;
      @             (((\result >>> p) & 1) == (((num >>> p) & 1) ^ ((p % 2 == 0) ? 1 : 0))));
      @ ensures (\forall int p; 0 <= p && p < 32 && (num >> p) <= 0;
      @             (((\result >>> p) & 1) == ((num >>> p) & 1)));
      @*/
	public static int evenBitToggleNumber(int num) {
		int result = 0;
		int ret = 0;
		int total = num;
        //@ maintaining 0 <= ret && ret <= 32;
        //@ maintaining total >= 0 && total == (num >> ret);
        //@ maintaining (\forall int p; 0 <= p && p < ret; (((result >>> p) & 1) == ((p % 2 == 0) ? 1 : 0)));
        //@ maintaining (\forall int p; ret <= p && p < 32; (((result >>> p) & 1) == 0));
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