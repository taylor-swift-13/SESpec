import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class CountNo {

    //@ requires a != 0;
    //@ requires l <= r;
    //@ requires n >= 0;
    //@ ensures (\result == -1) || (l <= \result && \result <= r);
 
 
    public static int countNo(int a, int n, int l, int r) {
        int count = 0;
        //@ maintaining l <= i && i <= r + 1;
 
 
        //@ decreases r - i + 1;
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
