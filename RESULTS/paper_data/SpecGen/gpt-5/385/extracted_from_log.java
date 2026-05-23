import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class RoundNum {

    /*@
      @ requires m != 0;
      @ ensures n < 0 ==> \result == -1;
      @ ensures n >= 0 ==> (0 <= \result && \result <= n && \result % m == 0);
      @*/
    public static int roundNum(int n, int m) {
        //@ maintaining m != 0 && i <= n;
        for (int i = n; i >= 0; i--) {
            if (i % m == 0) {
                return i;
            }
        }
        return -1;
    }
}