import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class JacobsthalNum {

    //@ requires j >= 0;
    //@ ensures \result == (j == 0 ? 0 : (j == 1 ? 1 : jacobsthalNum(j - 1) + 2 * jacobsthalNum(j - 2)));
    public static int jacobsthalNum(int j) {
        int r[] = new int[j + 1];
        r[0] = 0;
        r[1] = 1;
        //@ maintaining 2 <= p && p <= j + 1;
        //@ maintaining (\forall int k; 2 <= k && k < p; r[k] == r[k - 1] + 2 * r[k - 2]);
        //@ decreases j - p + 1;
        for (int p = 2; p <= j; p++) {
            r[p] = r[p - 1]
                    + 2 * r[p - 2];
        }
        return r[j];
    }
}