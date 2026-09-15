import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class CountNoOfWays {

    //@ requires n >= 0 && k >= 0;
    //@ requires n < Integer.MAX_VALUE - 1;
    //@ ensures n == 0 ==> \result == 1;
    //@ ensures n == 1 ==> \result == k;
    //@ ensures n == 2 ==> \result == k * k;
    //@ ensures n >= 3 ==> \result >= 0;
    public static int countNoOfWays(int n, int k) {
        int mod = 1000000007;
        int dp[] = new int[n+1];
        dp[0] = 1;
        if (n >= 1) {
            dp[1] = k;
        }
        if (n >= 2) {
            dp[2] = k*k;
        }
 
        //@ maintaining dp.length == n + 1;
        //@ maintaining dp[0] == 1;
        //@ maintaining (n >= 1 ==> dp[1] == k);
        //@ maintaining (n >= 2 ==> dp[2] == k * k);
        //@ decreases n - i + 1;
        for(int i=3;i<=n;i++){
            dp[i] = ((k-1) * (dp[i-1] + dp[i-2])) % mod;
        }
        return dp[n];
    }
}