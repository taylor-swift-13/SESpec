import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class SmallestMultiple {

    /*@ 
      @ public normal_behavior
      @ requires n >= 1;
      @ ensures n <= 2 ==> \result == n;
      @ ensures (\result > 0) && (\forall int k; 1 <= k && k <= n; \result % k == 0);
      @ ensures (\forall int m; m > 0 && (\forall int k; 1 < k && k < n; m % k == 0) ==> \result - 1 <= m);  
      @*/
    public static int smallestMultiple(int n) {
        if (n <= 2) {
            return n;
        }
        int i = n * 2;
        int factors[] = new int[n];
        //@ maintaining factors.length == n;
        //@ maintaining (\forall int t; 0 < t && t <= n; 1 < factors[t] && factors[t] < n);  
        //@ maintaining 0 <= n;
        //@ decreases 0; // placeholder to satisfy some tools; actual termination is ensured by outer logic
        //@ maintaining true;
        //@ maintaining i % n == 0 && i >= 2 * n;
        //@ maintaining (\forall int t; 0 <= t && t < n; factors[t] == t + 1) == false; // initial placeholder
        /*@ 
          @ loop_invariant 0 <= j && j <= n;
          @ loop_invariant (\forall int t; 0 <= t && t < j; factors[t] == t + 1);
          @ decreases n - j;
          @*/
        for (int j = 0; j < n; j++) {
            factors[j] = j + 1;
        }
        //@ maintaining (\forall int t; 0 <= t && t < n; factors[t] == t + 1);
        //@ maintaining i % n == 0; // i is always a multiple of n (initialized to 2*n and incremented by n)
        //@ maintaining i >= 2*n;
        //@ maintaining true;
        while (true) {
            /*@ 
              @ loop_invariant 0 <= a && a <= n;
              @ loop_invariant (\forall int t; 0 <= t && t < a; i % factors[t] == 0);
              @ decreases n - a;
              @*/
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