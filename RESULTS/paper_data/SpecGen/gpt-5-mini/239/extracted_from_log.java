import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindMissing {

    //@ requires ar != null;
    //@ requires n >= 0;
    //@ requires ar.length >= n;
    //@ ensures n == 0 ==> \result == 1;
    //@ ensures n >= 1 ==> 1 <= \result && \result <= n;
 
    //@ ensures \result < n ==> ar[\result - 1] != \result;
 
    public static int findMissing(int[] ar, int n) {
        int missing = 1;
        if (n == 0 || n == 1) {
            return missing;
        }
        /*@ 
          @ maintaining 1 <= i && i <= n+1;
 
          @ maintaining (i == 1 ? missing == 1 : missing == i-1);
          @ decreases n - i + 1;
          @*/
        for (int i = 1; i <= n; i++) {
            if (ar[i - 1] == i) {
                missing = i;
            } else if (ar[i - 1] != i) {
                return i;
            }
        }
        return missing;
    }
}