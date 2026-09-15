import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class EvenBinomialCoeffSum {

    //@ requires n >= 0;
 
    //@ ensures n == 0 ==> \result == 1;
 
    public static int evenBinomialCoeffSum(int n) {
        int sum = 0;
        int[] dp = new int[n + 1];
        dp[0] = 1;
        //@ maintaining 1 <= i && i <= n + 1;
        //@ maintaining dp != null && dp.length == n + 1;
        //@ maintaining dp[0] == 1;
        //@ maintaining (\exists int k; 1 - 1 <= k && k < i; dp[k] > 0);  
        //@ decreases n - i + 1;
        for (int i = 1; i <= n; i++) {
            //@ maintaining 0 <= j && j <= i;
            //@ maintaining dp != null && dp.length == n + 1;
            //@ maintaining dp[0] == 1;
 
            //@ maintaining (\exists int k; 0 <= k && k < i; dp[k] > 0);  
            //@ decreases i - j;
            for (int j = 0; j < i; j++) {
                dp[i] = dp[i] + dp[j];
            }
        }
        return dp[n];
    }
}