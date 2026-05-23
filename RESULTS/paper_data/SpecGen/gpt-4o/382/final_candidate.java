import java.io.*;
import java.lang.*;

class FindMaxVal {

    //@ requires n > 0 && x > 0 && y >= 0 && y < x;
    //@ ensures (\result == 0 ==> (\forall int i; 1 <= i && i <= n; i % x != y));
    //@ ensures (\result > 0 ==> (\result % x == y && (\forall int i; 1 <= i && i <= n; i % x == y ==> i <= \result)));
    //@ ensures \result >= 0 && \result <= n;
    public static int findMaxVal(int n, int x, int y) {
        int max = 0;
        //@ loop_invariant 1 <= i && i <= n + 1;
        //@ loop_invariant max >= 0 && max <= n;
        //@ loop_invariant (\forall int j; 1 <= j && j < i; (j % x == y) ==> max >= j);
        //@ decreases n - i + 1;
        for (int i = 1; i <= n; i++) {
            if ((i % x) == y) {
                max = i;
            }
        }
        return max;
    }
}