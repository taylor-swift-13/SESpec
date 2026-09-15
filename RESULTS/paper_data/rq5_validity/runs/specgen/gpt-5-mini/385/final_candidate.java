import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class RoundNum {

    /*@
      @ requires m != 0 && n >= 0;
      @ ensures (\result == -1) <==> (\forall int i; 0 <= i && i <= n; i % m != 0);
 
      @          (0 <= \result && \result <= n && \result % m == 0 && \result + m > n);
      @*/
    public static int roundNum(int n, int m) {
        /*@ maintaining 0 <= i && i <= n;
          @ maintaining (\forall int k; i < k && k <= n ==> k % m != 0);
          @ decreases i + 1;
          @*/
        for (int i = n; i >= 0; i--) {
            if (i % m == 0) {
                return i;
            }
        }
        return -1;
    }
}
