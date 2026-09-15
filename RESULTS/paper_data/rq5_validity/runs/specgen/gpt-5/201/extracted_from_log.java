import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class CountWays {

    //@ requires n >= 1;
    //@ ensures true;
    public static int countWays(int n) {
        int[] A = new int[n+1];
        int[] B = new int[n+1];
        A[0] = 1;
        A[1] = 0;
        B[0] = 0;
        B[1] = 1;
        //@ maintaining A != null && B != null && A.length == n + 1 && B.length == n + 1;
        //@ maintaining 2 <= i && i <= n + 1;
        //@ maintaining i <= n ==> (0 <= i-2 && i-2 < A.length && 0 <= i-1 && i-1 < B.length && 0 <= i && i < A.length && 0 <= i && i < B.length);
        //@ decreases n - i;
        for(int i = 2; i <= n; i++) {
            A[i] = A[i-2] + 2 * B[i-1];
            B[i] = A[i-1] + B[i-2];
        }
        return A[n];
    }
}