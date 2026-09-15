import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class CountNo {

    //@ requires a != 0;
    //@ requires n > 0;
    //@ ensures (\result == -1) <==> ((\num_of int i; l <= i && i <= r; i % a != 0) < n);
    //@ ensures (\result != -1) ==> (l <= \result && \result <= r && (\result % a) != 0
    //@                             && (\num_of int i; l <= i && i <= \result; i % a != 0) == n);
    public static int countNo(int a, int n, int l, int r) {
        int count = 0;
        //@ maintaining l <= i && i <= r + 1;
        //@ maintaining 0 <= count && count == (\num_of int j; l <= j && j < i; j % a != 0);
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