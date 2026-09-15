import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class SmallestMultiple {

    /*@ ensures n <= 2 ==> \result == n;
      @ ensures n > 2 ==> \result % n == 0;
      @*/
    public static int smallestMultiple(int n) {
        if (n <= 2) {
            return n;
        }
        int i = n * 2;
        int factors[] = new int[n];
        //@ maintaining 0 <= j && j <= n;
        for (int j = 0; j < n; j++) {
            factors[j] = j + 1;
        }
        //@ maintaining true;
        while (true) {
            //@ maintaining 0 <= a && a <= n;
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