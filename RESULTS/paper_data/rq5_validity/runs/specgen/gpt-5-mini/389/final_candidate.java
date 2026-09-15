import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindNthDigit {

    /*@
      @ requires p >= 0 && q > 0 && p < q;
      @ requires n >= 0;
 
      @ ensures \old(n) > 0 ==> 0 <= \result && \result < 10;
      @*/
    public static int findNthDigit(int p, int q, int n) {
        int res = 0;
        /*@
          @ maintaining n >= 0;
          @ maintaining 0 <= res && res < 10;
          @ maintaining 0 <= p && p < q;
          @ decreases n;
          @*/
        while (n > 0) {
            n -= 1;
            p *= 10;
            res = p / q;
            p %= q;
        }
        return res;
    }
}
