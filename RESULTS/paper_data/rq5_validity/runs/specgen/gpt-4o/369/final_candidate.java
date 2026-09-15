import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindMaxVal {

    //@ requires value >= 0 && p > 0 && 0 <= dy && dy < p;
    //@ ensures \result == 0 || (\result % p == dy && 1 <= \result && \result <= value);
    //@ ensures (\exists int c; 1 < c && c < value; c % p == dy ==> c < \result);  
    public static int findMaxVal(int value, int p, int dy) {
        int result = 0;
        //@ maintaining 0 <= c && c <= value + 1;
        //@ maintaining result == 0 || (result % p == dy && 1 <= result && result < c);
        //@ decreases value - c + 1;
        for (int c = 1; c <= value; c++) {
            if ((c % p) == dy) {
                result = c;
            }
        }
        return result;
    }
}
