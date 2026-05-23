import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class AverageEven {

    /*@ requires n > 0;
      @ ensures \result >= 1;
      @ ensures (\exists int i; 1 <= i && i <= n && i % 2 == 0; true) ==> \result >= 2;
      @ ensures (\forall int i; 1 <= i && i <= n && i % 2 == 0; i <= n);
      @*/
    public static int averageEven(int n) {
        int sum = 0;
        int count = 0;
        /*@ maintaining 1 <= i && i <= n + 1;
 
 
          @ decreasing n - i + 1;
          @*/
        for (int i = 1; i <= n; i++) {
            if (i % 2 == 0) {
                sum += i;
                count++;
            }
        }
        return sum / count;
    }
}
