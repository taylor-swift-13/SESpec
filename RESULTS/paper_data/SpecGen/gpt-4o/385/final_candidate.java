import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class RoundNum {

    //@ requires n >= 0 && m > 0;
    //@ ensures \result == -1 <==> (\forall int i; 0 <= i && i <= n; i % m != 0);
    //@ ensures \result >= 0 ==> \result % m == 0 && \result <= n && (\forall int i; \result < i && i <= n; i % m != 0);
    public static int roundNum(int n, int m) {
        //@ maintaining n >= 0 && m > 0;
        //@ maintaining 0 <= i && i <= n;
        //@ maintaining (\forall int k; i < k && k <= n; k % m != 0);
        //@ decreases i;
        for (int i = n; i >= 0; i--) {
            if (i % m == 0) {
                return i;
            }
        }
        return -1;
    }
}