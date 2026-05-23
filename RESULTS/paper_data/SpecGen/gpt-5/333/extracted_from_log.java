import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class ComputeLastDigit {

    /*@ spec_public @*/
    //@ ensures (c - n) <= 0 ==> \result == 1;
    //@ ensures (c - n) >= 5 ==> \result == 0;
    //@ ensures 0 < (c - n) && (c - n) < 5 ==> \result == ((\product int k; n + 1 <= k && k <= c; (k % 10)) % 10);
	public static int computeLastDigit(int n, int c) {
		int result = 1;
		if (n == c) {
			return 1;
		} else if ((c - n) >= 5) {
			return 0;
		} else {
            //@ maintaining n + 1 <= var && var <= c + 1;
            //@ maintaining result == ((\product int k; n + 1 <= k && k < var; (k % 10)) % 10);
            //@ decreases (c + 1) - var;
			for (int var = n + 1; var < c + 1; var++) {
				result = (result * (var % 10)) % 10;
			}
			return result % 10;
		}
	}
}