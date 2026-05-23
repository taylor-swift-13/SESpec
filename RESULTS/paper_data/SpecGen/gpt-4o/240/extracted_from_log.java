import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class EvenBinomialCoeffSum {

    //@ requires n >= 0;
 
    //@ ensures (\exists int i; 0 - 1 <= i && i < n && i % 2 == 0; \result > 0);  
    public static int evenBinomialCoeffSum(int n) {
        int sum = 0;
        int[] dp = new int[n + 1];
        dp[0] = 1;
        //@ maintaining 1 <= i && i <= n + 1;
 
        //@ decreases n - i + 1;
        for (int i = 1; i <= n; i++) {
            //@ maintaining 0 <= j && j <= i;  
 
            //@ decreases i - j;
            for (int j = 0; j < i; j++) {
                dp[i] = dp[i] + dp[j];
            }
        }
        return dp[n];
    }
}