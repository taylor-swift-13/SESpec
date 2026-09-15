import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class JacobsthalLucas {

    /*@
      @ requires n >= 1;
      @ ensures \result == ((1 << n) + ((n % 2 == 0) ? 1 : -1));
      @*/
    /*@ spec_public @*/ public static int jacobsthalLucas(int n) {
        int dp[] = new int[n + 1];
        dp[0] = 2;
        dp[1] = 1;
        /*@
          @ // i ranges over the loop variable of for(int i=2; i<=n; i++)
          @ maintaining 2 <= i && i <= n + 1;
          @ maintaining (\forall int k; 0 <= k && k < i;
          @                 dp[k] == ((1 << k) + ((k % 2 == 0) ? 1 : -1)));
          @ decreases n - i + 1;
          @*/
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + 2 * dp[i - 2];
        }
        return dp[n];
    }
}