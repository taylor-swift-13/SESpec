import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindMaxVal {

    //@ requires n >= 0 && x > 0;
    //@ ensures 0 <= \result && \result <= n;
    //@ ensures \result == 0 || (\result % x) == y;
    public static int findMaxVal(int n, int x, int y) {
        int max = 0;
 
 
          @ decreasing n - i + 1;
          @*/
        for (int i = 1; i <= n; i++) {
            if ((i % x) == y) {
                max = i;
            }
        }
        return max;
    }
}
