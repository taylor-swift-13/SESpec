import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class SumOfOddFactors {

    /*@ 
      @ requires n >= 0;
      @ ensures \result == (\sum int i; 1 <= i && i <= n && n % i == 0 && i % 2 != 0; i);  
      @ ensures \result >= 0;
      @*/
    public static /*@ spec_public @*/ int sumOfOddFactors(int n) {
        int sum = 0;
        /*@
          @ maintaining 1 <= i && i <= n + 1;
 
          @ decreases n - i + 1;
          @*/
        for (int i = 1; i <= n; i++) {
            if (n % i == 0) {
                if (i % 2 != 0) {
                    sum += i;
                }
            }
        }
        return sum;
    }
}
