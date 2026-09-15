import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class BinomialCoeff {

    /*@ requires n >= 0 && k >= 0 && k <= n;
      @ ensures \result >= 1;
      @ ensures (\forall int i; 1 <= i && i <= k; \result % i == 0); // Result is divisible by all integers from 1 to k
      @ ensures (\forall int i; 1 <= i && i <= k; \result / i == (\old(\result) * (n - i + 1) / i)); // Intermediate calculation
      @*/
    public static int binomialCoeff(int n, int k) {
        if (k > n - k)
            k = n - k;
        int c = 1;
        /*@ maintaining 1 <= i && i <= k + 1;
          @ maintaining c >= 1;
          @ maintaining (\forall int j; 1 <= j && j < i; c % j == 0); // c is divisible by all integers from 1 to i-1
          @ decreases k - i + 1;
          @*/
        for (int i = 1; i <= k; i++) {
            c = c * (n - i + 1) / i;
        }
        return c;
    }
}