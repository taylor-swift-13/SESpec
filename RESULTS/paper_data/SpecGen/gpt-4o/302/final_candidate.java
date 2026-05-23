import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class JacobsthalNum {

    //@ requires n >= 0;
    //@ ensures \result == (n == 0 ? 0 : (n == 1 ? 1 : (jacobsthalNum(n - 1) + 2 * jacobsthalNum(n - 2))));
    public static int jacobsthalNum(int n) {
        int dp[] = new int[n + 1];
        dp[0] = 0;
        dp[1] = 1;
        //@ maintaining 2 <= i && i <= n + 1;
        //@ maintaining (\forall int k; 2 <= k && k < i; dp[k] == dp[k - 1] + 2 * dp[k - 2]);
        //@ decreases n - i + 1;
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + 2 * dp[i - 2];
        }
        return dp[n];
    }
}