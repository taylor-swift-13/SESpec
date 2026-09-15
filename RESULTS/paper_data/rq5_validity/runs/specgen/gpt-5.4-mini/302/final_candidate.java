import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class JacobsthalNum {

    /*@ requires n >= 1;
 
 
 
      @*/
    public static int jacobsthalNum(int n) {
        int dp[] = new int[n + 1];
        dp[0] = 0;
        dp[1] = 1;
        /*@ maintaining 2 <= i && i - 1 <= n;  
          @ maintaining dp.length == n + 1;
          @ maintaining dp[0] == 0;
          @ maintaining dp[1] == 1;
          @ decreases n - i;
          @*/
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + 2 * dp[i - 2];
        }
        return dp[n];
    }
}
