import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class GetInvCount {

    //@ requires args != null;
    //@ requires 0 <= num && num <= args.length;
    //@ assignable \nothing;
    //@ ensures (\forall int t; 0 <= t && t < args.length; args[t] == \old(args[t]));
    //@ ensures \result == (\sum int i; 0 <= i && i < num;
    //@                      (\sum int j; i + 1 <= j && j < num; (args[i] > args[j] ? 1 : 0)));
    //@ ensures 0 <= \result && \result <= (num * (num - 1)) / 2;
	public static int getInvCount(int[] args, int num) {
		int ret = 0;

        //@ maintaining 0 <= index && index <= num;
        //@ maintaining ret == (\sum int i; 0 <= i && i < index;
        //@                         (\sum int j; i + 1 <= j && j < num; (args[i] > args[j] ? 1 : 0)));
        //@ decreases num - index;
		for (int index = 0; index < num; index++) {
            //@ maintaining index + 1 <= k && k <= num;
            //@ maintaining ret == (\sum int i; 0 <= i && i < index;
            //@                         (\sum int j; i + 1 <= j && j < num; (args[i] > args[j] ? 1 : 0)))
            //@                     + (\sum int j; index + 1 <= j && j < k; (args[index] > args[j] ? 1 : 0));
            //@ decreases num - k;
			for (int k = index + 1; k < num; k++) {
				if (args[index] > args[k]) {
					ret++;
				}
			}
		}
		return ret;
	}
}