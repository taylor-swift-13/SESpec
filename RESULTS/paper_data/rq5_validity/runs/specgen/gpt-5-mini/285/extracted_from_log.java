import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class CountDivisors {

    /*@ 
      @ requires n >= 1;
      @ ensures (\num_of int d; 1 <= d && d <= n && n % d == 0; true) % 2 == 0 <==> \result.equals("Even");
      @ ensures (\num_of int d; 1 <= d && d <= n && n % d == 0; true) % 2 == 1 <==> \result.equals("Odd");
      @*/
    public static String countDivisors(int n) {
        int count = 0;
        /*@ 
          @ maintaining 1 <= i && i <= n+1;
          @ maintaining count == (\num_of int k; 1 <= k && k < i && n % k == 0; true);
          @ decreases n - i + 1;
          @*/
        for (int i = 1; i <= n; i++) {
            if (n % i == 0) {
                count++;
            }
        }
        if (count % 2 == 0) {
            return "Even";
        } else {
            return "Odd";
        }
    }
}