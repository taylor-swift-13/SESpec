import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class SmallestDivisor {

    /*@ public normal_behavior
      @   requires n >= 1;
 
      @         || (n >= 2
      @             && 2 <= \result && \result <= n
      @             && n % \result == 0
      @             && (\forall int k; 2 <= k && k < \result; n % k != 0));
      @*/
    public static int smallestDivisor(int n) {
        int i = 2;
        /*@ maintaining 2 <= i;
 
          @ decreases n - i + 1;
          @*/
        while (i <= n / i) {
            if (n % i == 0) {
                return i;
            }
            i++;
        }
        return n;
    }
}
