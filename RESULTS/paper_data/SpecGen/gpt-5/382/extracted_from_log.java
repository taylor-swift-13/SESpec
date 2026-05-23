import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindMaxVal {

    //@ requires n >= 0 && x != 0;
    //@ ensures 0 <= \result && \result <= n;
    //@ ensures (\result == 0) ==> (\forall int i; 1 <= i && i <= n; (i % x) != y);
    //@ ensures (\result != 0) ==> (1 <= \result && \result <= n && (\result % x) == y && (\forall int k; \result < k && k <= n; (k % x) != y));
    public static int findMaxVal(int n, int x, int y) {
        int max = 0;
        //@ maintaining 1 <= i && i <= n + 1;
        //@ maintaining 0 <= max && max < i;
        //@ maintaining (max == 0) || ((max % x) == y);
        //@ maintaining (\forall int k; 1 <= k && k < i; ((k % x) == y) ==> k <= max);
        //@ decreases n - i + 1;
        for (int i = 1; i <= n; i++) {
            if ((i % x) == y) {
                max = i;
            }
        }
        return max;
    }
}