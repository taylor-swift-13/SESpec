import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class EvenBitToggleNumber {

	/*@ 
	  @ requires number >= 0;
	  @ 
	  @ // The result toggles every even bit position that exists in the binary
	  @ // representation of number (i.e. for which (number >> k) != 0).
	  @ ensures (\forall int k; 0 <= k;
	  @            (k % 2 == 0 && ((number >> k) != 0))
	  @              ==> (((\result >> k) & 1) == 1 - ((number >> k) & 1)))
	  @         &&
	  @         (\forall int k; 0 <= k;
	  @            !(k % 2 == 0 && ((number >> k) != 0))
	  @              ==> (((\result >> k) & 1) == ((number >> k) & 1)));
	  @*/
	public static int evenBitToggleNumber(int number) {
		int i = 0;
		int ret = 0;
		int total = number;
		//@ maintaining ret >= 0;
		//@ maintaining total >= 0;
		//@ maintaining i >= 0;
		//@ maintaining (\forall int k; 0 <= k && k < ret && k % 2 == 0; (((i >> k) & 1) == 1));
		//@ maintaining (\forall int k; 0 <= k && k < ret && k % 2 == 1; (((i >> k) & 1) == 0));
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