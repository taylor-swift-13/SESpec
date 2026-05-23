import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class Difference {

    /*@ requires n >= 0;
      @ ensures \result == ((\sum int k; 1 <= k && k <= n; k*k*k)
      @                     - \sum int k; 1 <= k && k <= n; k);
      @*/
    public static int difference(int n) {
        int sum = 0;
        int sum1 = 0;
        /*@ maintaining 1 <= i && i <= n + 1;
          @ maintaining sum == (\sum int k; 1 <= k && k < i; k*k*k);
          @ decreases n - i + 1;
          @*/
        for (int i = 1; i <= n; i++) {
            sum += i * i * i;
        }
        /*@ maintaining 1 <= i && i <= n + 1;
          @ maintaining sum1 == (\sum int k; 1 <= k && k < i; k);
          @ decreases n - i + 1;
          @*/
        for (int i = 1; i <= n; i++) {
            sum1 += i;
        }
        return sum - sum1;
    }
}