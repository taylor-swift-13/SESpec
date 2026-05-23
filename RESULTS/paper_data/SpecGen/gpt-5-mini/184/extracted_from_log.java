import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class Sum {

    /*@ 
      @ requires n >= 0;
      @ // The result is the sum of distinct prime divisors of n
      @ ensures \result == (\sum int p; 2 <= p && p <= n 
      @                          && (\forall int d; 2 <= d && d <= p-1; p % d != 0) 
      @                          && n % p == 0; p);
      @*/
    public static int sum(int n) {
        int[] sumOfPrimeDivisors = new int[n + 1];
        sumOfPrimeDivisors[0] = 0;
        //@ assume 1 < sumOfPrimeDivisors.length;
        sumOfPrimeDivisors[1] = 0;

        /*@ 
          @ // Invariant: i ranges and for all k, sumOfPrimeDivisors[k] equals
          @ // the sum of prime divisors p of k with 2 <= p < i.
 
 
          @                 sumOfPrimeDivisors[k] 
          @                   == (\sum int p; 2 <= p && p < i
          @                                 && (\forall int d; 2 <= d && d <= p-1; p % d != 0)
          @                                 && k % p == 0; p));
          @ decreases n - i + 1;
          @*/
        for (int i = 2; i <= n; i++) {
            if (sumOfPrimeDivisors[i] == 0) {
                /*@ 
                  @ // Inner loop invariant: j iterates over multiples of i.
                  @ // For each k, sumOfPrimeDivisors[k] equals the sum of primes < i dividing k,
                  @ // plus i if k is a multiple of i that has already been processed (k < j).
                  @ maintaining i >= 2 && i <= n;
                  @ maintaining (\forall int k; 0 <= k && k <= n;
                  @                 sumOfPrimeDivisors[k] 
                  @                  == (\sum int p; 2 <= p && p < i
                  @                                && (\forall int d; 2 <= d && d <= p-1; p % d != 0)
                  @                                && k % p == 0; p)
                  @                     + ((k % i == 0 && k < j) ? i : 0));
                  @ maintaining j >= i && j <= n + i; 
                  @ decreases n - j + 1;
                  @*/
                for (int j = i; j <= n; j += i) {
                    sumOfPrimeDivisors[j] += i;
                }
            }
        }

        return sumOfPrimeDivisors[n];
    }
}