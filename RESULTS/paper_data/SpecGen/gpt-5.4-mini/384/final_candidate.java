import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class BinomialCoeff {

    //@ requires n >= 0 && k >= 0 && k <= n;
    //@ ensures \result >= 0;
    public static int binomialCoeff(int n, int k) {
        if (k > n - k)
            k = n - k;
        int c = 1;
        //@ maintaining 1 <= i && i <= k + 1;
        //@ maintaining c >= 1;
        //@ decreases k - i + 1;
        for (int i = 1; i <= k; i++) {
            c = c * (n - i + 1) / i;
        }
        return c;
    }
}