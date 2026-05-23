import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class BinomialCoeff {

    /*@ spec_public @*/
    /*@ 
      @ requires n >= 0;
      @ requires 0 <= k && k <= n;
      @ 
      @ // Let m be the effective number of multiplicative steps (uses symmetry)
      @ ensures (\let m = (\old(k) <= n - \old(k) ? \old(k) : n - \old(k));
      @          \result * (\product int i; 1 <= i && i <= m; i)
      @            == (\product int i; 1 <= i && i <= m; (n - i + 1)));
      @
      @ ensures \result >= 1;
      @ ensures (\old(k) == 0 || \old(k) == n) ==> \result == 1;
      @*/
    public static int binomialCoeff(int n, int k) {
        if (k > n - k)
            k = n - k;
        int c = 1;
        /*@ 
          @ // Loop invariants:
          @ //  - i is always between 1 and k+1 while the loop executes
          @ //  - c equals the product (for j from 1 to i-1) of (n-j+1)/j
          @ //    which is the binomial coefficient C(n, i-1)
          @ maintaining 1 <= i && i <= k + 1;
          @ maintaining c > 0;
          @ maintaining c * (\product int j; 1 <= j && j < i; j)
          @            == (\product int j; 1 <= j && j < i; (n - j + 1));
          @ decreases k - i + 1;
          @*/
        for (int i = 1; i <= k; i++) {
            c = c * (n - i + 1) / i;
        }
        return c;
    }
}