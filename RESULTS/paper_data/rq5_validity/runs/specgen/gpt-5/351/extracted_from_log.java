import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

/*@ spec_public @*/
class EvenBitToggleNumber {

    /*@ spec_public @*/
    //@ ensures number <= 0 ==> \result == number;
    //@ ensures number > 0 ==> (\exists int L; L >= 0 && (number >> L) == 0 && (L == 0 || (number >> (L - 1)) > 0) &&
    //@                         (\exists int mask; \result == (number ^ mask) &&
    //@                           (\forall int k; 0 <= k && k < 32;
    //@                             (((mask >> k) & 1) == (((k % 2) == 0 && k < L) ? 1 : 0)))) );
	public static int evenBitToggleNumber(int number) {
		int i = 0;
		int ret = 0;
		int total = number;
        //@ maintaining ret >= 0 && total == (number >> ret);
        //@ maintaining total >= 0;
        //@ maintaining (\forall int k; 0 <= k && k < ret;
        //@                (((k % 2) == 0) ==> (((i >> k) & 1) == 1)) &&
        //@                (((k % 2) != 0) ==> (((i >> k) & 1) == 0)));
        //@ maintaining (\forall int k; ret <= k && k < 32; ((i >> k) & 1) == 0);
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