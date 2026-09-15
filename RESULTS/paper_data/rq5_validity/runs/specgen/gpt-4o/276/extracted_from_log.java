import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class CountNoOfWays {

    //@ requires n >= 0 && k > 0;
 
    //@ ensures n == 0 ==> \result == 1;
    //@ ensures n == 1 ==> \result == k;
    //@ ensures n == 2 ==> \result == k * k;
 
    public static int countNoOfWays(int n, int k) {
        int mod = 1000000007;
        if (n == 0) return 1;
        if (n == 1) return k;
        if (n == 2) return k * k;

        int prev1 = k;
        int prev2 = k * k;
        int current = 0;

        //@ maintaining 3 <= i && i <= n + 1;
 
        //@ decreases n - i + 1;
        for (int i = 3; i <= n; i++) {
            current = ((k - 1) * (prev1 + prev2)) % mod;
            prev2 = prev1;
            prev1 = current;
        }
        return current;
    }

    //@ requires n > 2 && k > 0 && mod > 0;
 
    //@ spec_public
    private static int computeWays(int n, int k, int mod) {
        int prev1 = k;
        int prev2 = k * k;
        int current = 0;

        for (int i = 3; i <= n; i++) {
            current = ((k - 1) * (prev1 + prev2)) % mod;
            prev2 = prev1;
            prev1 = current;
        }
        return current;
    }
}