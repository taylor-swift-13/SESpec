import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindNthDigit {

    /*@
      @ requires q > 0;
      @ requires n >= 0;
      @ requires 0 <= p && p < q;
      @ // to prevent overflow in p *= 10 at each iteration, since p < q holds at loop heads
      @ requires q <= Integer.MAX_VALUE / 10;
      @
      @ ensures (\old(n) <= 0) ==> (\result == 0);
      @ ensures (\old(n) > 0) ==> (0 <= \result && \result <= 9);
      @*/
    public static int findNthDigit(int p, int q, int n) {
        int res = 0;
        //@ maintaining q > 0;
        //@ maintaining 0 <= n;
        //@ maintaining 0 <= p && p < q;
        //@ maintaining 0 <= res && res <= 9;
        //@ decreases n;
        while (n > 0) {
            n -= 1;
            p *= 10;
            res = p / q;
            p %= q;
        }
        return res;
    }
}