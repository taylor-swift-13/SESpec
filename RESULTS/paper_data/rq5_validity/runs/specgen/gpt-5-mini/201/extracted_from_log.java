import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class CountWays {

    /*@
      requires n >= 1;
      ensures \result >= 0;
    @*/
    public static int countWays(int n) {
        int[] A = new int[n+1];
        int[] B = new int[n+1];
        A[0] = 1;
        A[1] = 0;
        B[0] = 0;
        B[1] = 1;
        //@ maintaining 2 <= i && i <= n+1;
        //@ maintaining A.length == n+1 && B.length == n+1;
        //@ maintaining A[0] == 1 && A[1] == 0 && B[0] == 0 && B[1] == 1;
        //@ maintaining (\forall int j; 0 <= j && j < i ==> A[j] >= 0 && B[j] >= 0);
        //@ decreases n - i + 1;
        for(int i = 2; i <= n; i++) {
            A[i] = A[i-2] + 2 * B[i-1];
            B[i] = A[i-1] + B[i-2];
        }
        return A[n];
    }
}