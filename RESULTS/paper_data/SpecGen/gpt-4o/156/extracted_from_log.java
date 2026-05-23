import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class MaxProduct {

    //@ requires args != null && args.length == Array && Array > 0;
    //@ ensures (\forall int i; 0 < i && i < args.length; args[i] > 0);  
    //@ ensures \result >= 0;
    //@ ensures \result == (\max int i; 0 <= i && i < Array; (\max int j; 0 <= j && j < i; args[i] > args[j] ? args[i] * (\max int k; 0 <= k && k < j; args[k]) : args[i]));
    public static int maxProduct(int[] args, int Array) {
        int[] mpis = new int[Array];
        //@ maintaining 0 <= array && array <= Array;
        //@ maintaining (\forall int i; 0 <= i && i < array; mpis[i] == args[i]);
        //@ decreases Array - array;
        for (int array = 0; array < Array; array++) {
            mpis[array] = args[array];
        }
        //@ maintaining 1 <= i && i <= Array;
        //@ maintaining (\forall int j; 0 <= j && j < i; (\forall int k; 0 <= k && k < j; args[j] > args[k] ==> mpis[j] >= mpis[k] * args[j]));
        //@ decreases Array - i;
        for (int i = 1; i < Array; i++) {
            //@ maintaining 0 <= p && p <= i;
            //@ maintaining (\forall int q; 0 <= q && q < p; args[i] > args[q] ==> mpis[i] >= mpis[q] * args[i]);
            //@ decreases i - p;
            for (int p = 0; p < i; p++) {
                if (args[i] > args[p]
                        && mpis[i] < (mpis[p] * args[i])) {
                    mpis[i] = mpis[p] * args[i];
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