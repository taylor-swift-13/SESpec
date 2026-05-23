import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class CatalanNumber {

    /*@ spec_public @*/
    //@ requires num >= 0;
    //@ ensures \result >= 0;
    //@ ensures (\exists int[] c; c.length == num + 1
    //@                      && c[0] == 1
    //@                      && (\forall int i; 1 <= i && i <= num;
    //@                             c[i] == \sum int j; 0 <= j && j < i; c[j] * c[i - j - 1])
    //@                      && \result == c[num]);
    public static int catalanNumber(int num) {
        int[] catalan = new int[num + 1];
        catalan[0] = 1;
        //@ maintaining catalan.length == num + 1;
        //@ maintaining catalan[0] == 1;
        //@ maintaining 1 <= i && i <= num + 1;
        //@ maintaining (\forall int k; 0 <= k && k < i;
        //@                  (k == 0
        //@                      ? catalan[k] == 1
        //@                      : catalan[k] == \sum int t; 0 <= t && t < k; catalan[t] * catalan[k - t - 1]));
        //@ maintaining (\forall int k; 0 <= k && k < i; catalan[k] >= 0);
        //@ decreases num - i + 1;
        for (int i = 1; i <= num; i++) {
            catalan[i] = 0;
            //@ maintaining 0 <= j && j <= i;
            //@ maintaining catalan[i] == \sum int k; 0 <= k && k < j; catalan[k] * catalan[i - k - 1];
            //@ maintaining (\forall int k; 0 <= k && k < i;
            //@                  (k == 0
            //@                      ? catalan[k] == 1
            //@                      : catalan[k] == \sum int t; 0 <= t && t < k; catalan[t] * catalan[k - t - 1]));
            //@ maintaining (\forall int k; 0 <= k && k < i; catalan[k] >= 0);
            //@ decreases i - j;
            for (int j = 0; j < i; j++) {
                catalan[i] += catalan[j] * catalan[i - j - 1];
            }
        }
        return catalan[num];
    }
}