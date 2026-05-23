import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class JacobsthalLucas {

    //@ requires n >= 1;
    //@ ensures \result == jacobsthalLucas(n);
    public static int jacobsthalLucas(int n) {
        int dp[] = new int[n + 1];
        dp[0] = 2;
        dp[1] = 1;
        //@ maintaining 2 <= i && i <= n + 1;
        //@ maintaining dp[0] == 2 && dp[1] == 1;
        //@ maintaining (\forall int j; 2 <= j && j < i; dp[j] == dp[j - 1] + 2 * dp[j - 2]);
        //@ decreases n - i + 1;
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + 2 * dp[i - 2];
        }
        return dp[n];
    }
}