import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class NcrModP {

    //@ requires p > 0;
    //@ requires n >= 0 && r >= 0;
    //@ ensures (n < r) ==> \result == 0;
    //@ ensures (n >= r) ==> (0 <= \result && \result < p);
    public static int ncrModP(int n, int r, int p) {
        if (n < r) {
            return 0;
        }

        int ncr = 1;
        //@ maintaining 1 <= i && i <= r + 1;
        //@ maintaining ncr >= 0;
        //@ decreases r - i + 1;
        for (int i = 1; i <= r; i++) {
            ncr = (ncr * (n - i + 1)) / i;
        }

        return ncr % p;
    }
}