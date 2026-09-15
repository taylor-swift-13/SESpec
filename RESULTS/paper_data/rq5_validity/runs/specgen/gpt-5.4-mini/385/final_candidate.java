import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class RoundNum {

    //@ requires m != 0;
    //@ ensures (\result == -1) || (\result >= 0 && \result <= n && \result % m == 0);
    //@ ensures (\result == -1) <==> (\forall int i; 0 <= i && i <= n; i % m != 0);
    public static int roundNum(int n, int m) {
        //@ maintaining 0 < i && i < n;  
        //@ maintaining (\forall int j; i < j && j <= n; j % m != 0);
        //@ decreases i;
        for (int i = n; i >= 0; i--) {
            if (i % m == 0) {
                return i;
            }
        }
        return -1;
    }
}
