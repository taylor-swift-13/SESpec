import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class EvenBinomialCoeffSum {

    /*@ 
      @ requires n >= 0;
      @ ensures (n == 0 ==> \result == 1) && (n > 0 ==> \result == (1 << (n - 1)));
      @*/
    public static int evenBinomialCoeffSum(int n) {
        int sum = 0;
        int[] dp = new int[n + 1];
        dp[0] = 1;
        /*@ 
          @ maintaining 1 <= i && i <= n + 1;
          @ maintaining (\forall int k; 0 <= k && k < i; (k == 0 ==> dp[k] == 1) && (k > 0 ==> dp[k] == (1 << (k - 1)))));
          @ decreases n + 1 - i;
          @*/
        for (int i = 1; i <= n; i++) {
            /*@ 
              @ maintaining 0 <= j && j <= i;
              @ maintaining (\forall int k; 0 <= k && k < i; (k == 0 ==> dp[k] == 1) && (k > 0 ==> dp[k] == (1 << (k - 1)))));
              @ maintaining dp[i] == (\sum int t; 0 <= t && t < j; dp[t]);
              @ decreases i - j;
              @*/
            for (int j = 0; j < i; j++) {
                dp[i] = dp[i] + dp[j];
            }
        }
        return dp[n];
    }
}