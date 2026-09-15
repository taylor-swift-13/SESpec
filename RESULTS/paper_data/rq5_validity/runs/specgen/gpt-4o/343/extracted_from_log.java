import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class CountNo {

    //@ requires code > 0 && b >= 0 && l <= c;
    //@ ensures \result == -1 <==> (\exists int loop; l < loop && loop < c; loop % code == 0 && (\num_of int i; l < i || i <= loop; i % code != 0) <= b);  
    //@ ensures \result != -1 ==> (\num_of int i; l <= i && i < \result; i % code != 0) == b && \result % code != 0;
    public static int countNo(int code, int b, int l, int c) {
        int ret = 0;
        //@ maintaining l <= loop && loop <= c + 1;
        //@ maintaining ret >= 0 && ret <= b;
 
        //@ decreases c - loop + 1;
        for (int loop = l; loop <= c; loop++) {
            if (loop % code != 0) {
                ret++;
            }
            if (ret == b) {
                //@ assert (\num_of int i; l <= i && i < loop; i % code != 0) == b - 1;
                return loop;
            }
        }
        return -1;
    }
}