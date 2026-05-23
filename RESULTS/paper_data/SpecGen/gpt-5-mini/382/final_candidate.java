import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindMaxVal {

    /*@
      requires n >= 0;
      requires x > 0;
      requires 0 <= y && y < x;
      ensures 0 <= \result && \result <= n;
      ensures (\result == 0) <==> (\forall int j; 1 <= j && j <= n; j % x != y);
      ensures \result > 0 ==> (\result % x == y);
    @*/
    public /*@ spec_public @*/ static int findMaxVal(int n, int x, int y) {
        int max = 0;
        /*@
          maintaining 0 <= max && max <= n;
          maintaining max == 0 || (1 <= max && max < i && max % x == y);
          decreases n - i + 1;
        @*/
        for (int i = 1; i <= n; i++) {
            if ((i % x) == y) {
                max = i;
            }
        }
        return max;
    }
}