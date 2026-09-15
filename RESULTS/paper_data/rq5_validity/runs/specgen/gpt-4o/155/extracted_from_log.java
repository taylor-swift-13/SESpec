import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class MaxProduct {

    //@ requires args != null && args.length == Array && Array > 0;
    //@ requires (\forall int i; 0 <= i && i < Array; args[i] >= 0);
 
    //@ ensures (\exists int i; 0 <= i && i <= Array; \result >= args[i]);  
    public static int maxProduct(int[] args, int Array) {
        int[] mpis = new int[Array];
        //@ maintaining 0 <= array && array <= Array;
        //@ maintaining (\forall int i; 0 <= i && i < array; mpis[i] == args[i]);
        //@ decreases Array - array;
        for (int array = 0; array < Array; array++) {
            mpis[array] = args[array];
        }
        //@ maintaining 1 <= i && i <= Array;
        //@ maintaining (\forall int j; 1 <= j && j < i; (\forall int k; 0 <= k && k < j; (args[j] > args[k] && mpis[j] >= mpis[k] * args[j]) || args[j] <= args[k]));
        //@ decreases Array - i;
        for (int i = 1; i < Array; i++) {
            //@ maintaining 0 <= k && k <= i;
            //@ maintaining (\forall int j; 0 <= j && j < k; (args[i] > args[j] && mpis[i] >= mpis[j] * args[i]) || args[i] <= args[j]);
            //@ decreases i - k;
            for (int k = 0; k < i; k++) {
                if (args[i] > args[k]
                        && mpis[i] < (mpis[k] * args[i])) {
                    mpis[i] = mpis[k] * args[i];
                }
            }
        }
        int num = mpis[0];
        //@ maintaining 1 <= i && i <= Array;
        //@ maintaining (\forall int j; 0 <= j && j < i; num >= mpis[j]);
        //@ decreases Array - i;
        for (int i = 1; i < Array; i++) {
            if (mpis[i] > num) {
                num = mpis[i];
            }
        }
        return num;
    }
}