import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class MaxPrimeFactors {

    //@ requires n > 1;
    //@ ensures \result == 0 || (\result > 1 && n % \result == 0);
    //@ ensures (\forall int p; p > 1 && p <= n && n % p == 0; p <= \result);
    public static int maxPrimeFactors(int n) {
        int max = 0;
        //@ maintaining 0 <= max && max <= n;
        //@ maintaining n > 0;
        //@ decreases n;
        for (int i = 2; i <= n; i++) {
 
            //@ maintaining max >= 0;
            //@ decreases n - i + 1;
            while (n % i == 0) {
                max = i;
                n /= i;
            }
        }
        return max;
    }
}
