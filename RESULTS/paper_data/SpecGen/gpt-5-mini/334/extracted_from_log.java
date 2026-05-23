import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class Difference {

    /*@ public normal_behavior
 
      @                    - (\sum int i; 1 <= i && i <= n; i);
      @   assignable \nothing;
      @*/
    /*@ spec_public @*/
    public static int difference(int n) {
        int sum = 0;
        int sum1 = 0;
        /*@ 
          @ maintaining (n < 1 && i == 1) || (1 <= i && i <= n+1);
 
          @*/
        for (int i = 1; i <= n; i++) {
            sum += i * i * i;
        }
        /*@ 
          @ maintaining (n < 1 && i == 1) || (1 <= i && i <= n+1);
 
          @*/
        for (int i = 1; i <= n; i++) {
            sum1 += i;
        }
        return sum - sum1;
    }
}