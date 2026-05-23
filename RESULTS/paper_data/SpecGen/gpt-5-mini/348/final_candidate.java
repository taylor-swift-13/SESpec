import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class CountNo {

    /*@ 
      requires a != 0;
      ensures (\result == -1) <==> ((\sum int j; l <= j && j <= r; (j % a != 0 ? 1 : 0)) < n);
      ensures \result != -1 ==>
               (l <= \result && \result <= r
                && (\sum int j; l <= j && j <= \result; (j % a != 0 ? 1 : 0)) == n
                && \result % a != 0);
    @*/
    public static int countNo(int a, int n, int l, int r) {
        int count = 0;
        /*@ 
          loop_invariant l <= i && i <= r + 1 &&
                         count == (\sum int j; l <= j && j < i; (j % a != 0 ? 1 : 0));
          loop_invariant count >= 0;
          decreases r - i + 1;
        @*/
        for (int i = l; i <= r; i++) {
            if (i % a != 0) {
                count++;
            }
            if (count == n) {
                return i;
            }
        }
        return -1;
    }
}