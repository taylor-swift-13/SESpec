import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class BinomialCoeff {

    //@ requires n >= 0 && 0 <= k && k <= n;
    //@ ensures (\let int kk = ((\old(k) > n - \old(k)) ? n - \old(k) : \old(k));
    //@           \result == ((\product int i; 1 <= i && i <= kk; (n - i + 1)) / (\product int i; 1 <= i && i <= kk; i)));
    //@ ensures (\old(k) == 0 || \old(k) == n) ==> \result == 1;
    public static int binomialCoeff(int n, int k) {
        if (k > n - k)
            k = n - k;
        int c = 1;
        //@ maintaining 1 <= i && i <= k + 1;
        //@ maintaining c == ((\product int t; 1 <= t && t < i; (n - t + 1)) / (\product int t; 1 <= t && t < i; t));
        //@ decreases k - i + 1;
        for (int i = 1; i <= k; i++) {
            c = c * (n - i + 1) / i;
        }
        return c;
    }
}