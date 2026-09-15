import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindOddPair {

    /*@ requires a != null;
      @ ensures \result == (\sum int i; 0 <= i && i < a.length;
      @                         (\sum int j; i + 1 <= j && j < a.length;
      @                              (((a[i] ^ a[j]) % 2 == 1) ? 1 : 0)));
      @ ensures 0 <= \result && \result <= (a.length * (a.length - 1)) / 2;
      @ ensures (\forall int k; 0 <= k && k < a.length; a[k] == \old(a[k]));
      @*/
    public static int findOddPair(int[] a, int n) {
        int count = 0;
        int length = a.length;
        //@ maintaining 0 <= i && i <= length;
        //@ maintaining length == a.length;
        //@ maintaining count == (\sum int p; 0 <= p && p < i;
        //@                           (\sum int q; p + 1 <= q && q < length;
        //@                                (((a[p] ^ a[q]) % 2 == 1) ? 1 : 0)));
        //@ decreases length - i;
        for (int i = 0; i < length; i++) {
            //@ maintaining i + 1 <= j && j <= length;
            //@ maintaining length == a.length;
            //@ maintaining count == (\sum int p; 0 <= p && p < i;
            //@                           (\sum int q; p + 1 <= q && q < length;
            //@                                (((a[p] ^ a[q]) % 2 == 1) ? 1 : 0)))
            //@                     + (\sum int q; i + 1 <= q && q < j;
            //@                                (((a[i] ^ a[q]) % 2 == 1) ? 1 : 0));
            //@ decreases length - j;
            for (int j = i + 1; j < length; j++) {
                if ((a[i] ^ a[j]) % 2 == 1) {
                    count++;
                }
            }
        }
        return count;
    }
}