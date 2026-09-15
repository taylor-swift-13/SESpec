import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class AverageOdd {

    /*@ 
      @ requires n >= 1;
      @ ensures \result == (\sum int i; 1 <= i && i <= n && i % 2 != 0; i) 
      @                  / (\sum int i; 1 <= i && i <= n && i % 2 != 0; 1);
      @ ensures 1 <= \result && \result <= n;
      @*/
    public static int averageOdd(int n) {
        int sum = 0;
        int count = 0;
        /*@
          @ maintaining 1 <= i && i <= n + 1;
 
 
          @ decreases n - i + 1;
          @*/
        for (int i = 1; i <= n; i++) {
            if (i % 2 != 0) {
                sum += i;
                count++;
            }
        }
        return sum / count;
    }
}
