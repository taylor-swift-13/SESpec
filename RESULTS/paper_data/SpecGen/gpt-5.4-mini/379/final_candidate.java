import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class SumEven {

    /*@ public normal_behavior
      @ requires l <= r;
 
      @ ensures \result > 0 || (\exists int i; l < i && i < r || i % 2 == 0; i < 0);  
      @ assignable \nothing;
      @*/
    public static int sumEven(int l, int r) {
        int sum = 0;
        /*@ maintaining l <= i && i <= r + 1;
 
          @ decreases r - i + 1;
          @*/
        for (int i = l; i <= r; i++) {
            if (i % 2 == 0) {
                sum += i;
            }
        }
        return sum;
    }
}
