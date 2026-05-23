import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class Last {

    //@ requires args != null;
    //@ requires 0 <= y && y <= args.length;
    //@ requires (\forall int i; 0 <= i && i + 1 < y; args[i] <= args[i+1]);
    //@ assignable \nothing;
    //@ ensures \result == -1 || (0 <= \result && \result < y && args[\result] == x);
	public static int last(int[] args, int x, int y) {
		int i = 0;
		int r = y - 1;
		int p = -1;

        //@ maintaining 0 <= i && i <= y && -1 <= r && r < y;
        //@ maintaining p == -1 || (0 <= p && p < i && args[p] == x);
        //@ decreases r - i + 1;
		while (i <= r) {
			int tmp = (i + r) / 2;
			if (args[tmp] == x) {
				p = tmp;
				i = tmp + 1;
			} else if (args[tmp] < x) {
				i = tmp + 1;
			} else {
				r = tmp - 1;
			}
		}

		return p;
	}
}