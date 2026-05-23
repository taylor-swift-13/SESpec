import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class SmallestMultiple {

    //@ requires n >= 1;
    //@ ensures \result == n || \result > n;
    public static int smallestMultiple(int n) {
        if (n <= 2) {
            return n;
        }
        int i = n * 2;
        int factors[] = new int[n];
        //@ maintaining 0 <= j && j <= n;
        //@ maintaining (\forall int k; 0 <= k && k < j; factors[k] == k + 1);
        //@ decreases n - j;
        for (int j = 0; j < n; j++) {
            factors[j] = j + 1;
        }
        //@ maintaining i >= 2 * n;
        while (true) {
            //@ maintaining 0 <= a && a <= n;
            //@ maintaining i >= 2 * n;
            //@ decreases n - a;
            for (int a = 0; a < n; a++) {
                if (i % factors[a] != 0) {
                    i += n;
                    break;
                }
                if (factors[a] == factors[n - 1] && i % factors[a] == 0) {
                    return i;
                }
            }
        }
    }
}