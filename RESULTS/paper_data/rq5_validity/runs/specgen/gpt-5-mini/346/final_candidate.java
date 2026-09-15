import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class MaxPrimeFactors {

    /*@ 
      @ requires n >= 0;
      @ ensures (\result == 0) <==> (\exists int p; 2 <= p && p - 1 <= \old(n); \old(n) % p != 0);  
      @ ensures \result >= 0;
      @ ensures \result != 0 ==>
      @   (\old(n) % \result == 0 &&
      @    (\forall int d; 2 <= d && d * d <= \result; \result % d != 0) &&
      @    (\forall int q; 2 <= q && q <= \old(n); (\old(n) % q == 0) ==> q <= \result));
      @*/
    public static int maxPrimeFactors(int n) {
        int max = 0;
        /*@ 
          @ maintaining 2 <= i && i - 1 <= \old(n) + 1;  
          @ maintaining 0 <= max;
          @ maintaining (\forall int p; 2 <= p && p < i; (\old(n) % p == 0) ==> p <= max);
          @ maintaining n >= 0;
          @ decreases \old(n) - i + 1;
          @*/
        for (int i = 2; i <= n; i++) {
            /*@ 
              @ maintaining i >= 2;
              @ maintaining n >= 0;
              @ maintaining 0 <= max;
              @ maintaining (max == 0) || (\old(n) % max == 0);
              @ decreases n;
              @*/
            while (n % i == 0) {
                max = i;
                n /= i;
            }
        }
        return max;
    }
}
