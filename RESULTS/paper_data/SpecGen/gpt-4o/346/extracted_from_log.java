import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class MaxPrimeFactors {

    //@ requires n > 0;
    //@ ensures \result >= 0;  
    //@ ensures (\forall int p; 2 < p && p <= n; (\exists int k; k > 0 && n % p == 0) ==> (\forall int d; 2 <= d && d <= p; p % d != 0));  
    //@ ensures (\forall int q; 2 <= q && q <= n; n % q == 0 ==> \result >= q);
    public static int maxPrimeFactors(int n) {
        int max = 0;
        //@ maintaining 2 <= i && i <= n + 1;
        //@ maintaining max >= 0;
        //@ maintaining (\forall int p; 2 <= p && p < i; n % p == 0 ==> (\forall int d; 2 <= d && d < p; p % d != 0));
        //@ maintaining (\forall int p; 2 <= p && p < i; n % p == 0 ==> max >= p);
        //@ decreases n - i;
        for (int i = 2; i <= n; i++) {
            //@ maintaining n >= 0;
            //@ maintaining n % i == 0 ==> max == i;
            //@ decreases n;
            while (n % i == 0) {
                max = i;
                n /= i;
            }
        }
        return max;
    }
}