import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class JacobsthalNum {

    /*@ public normal_behavior
      @   requires n >= 1;
 
 
      @*/
    public static int jacobsthalNum(int n) {
        int dp[] = new int[n + 1];
        dp[0] = 0;
        dp[1] = 1;
        /*@ 
          @   // i iterates from 2 up to n (after loop i == n+1)
          @   maintaining 2 <= i && i <= n + 1;
          @   maintaining dp[0] == 0 && dp[1] == 1;
          @   maintaining (\forall int k; 2 <= k && k < i;  
          @                  dp[k] == (((1 << k) - ((k % 2 == 0) ? 1 : -1)) / 3));
          @   decreases n - i + 1;
          @*/
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + 2 * dp[i - 2];
        }
        return dp[n];
    }
}
