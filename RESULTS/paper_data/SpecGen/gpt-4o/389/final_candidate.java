import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindNthDigit {

    //@ requires q > 0 && n > 0 && p >= 0;
 
    public static int findNthDigit(int p, int q, int n) {
        int res = 0;
        //@ maintaining n >= 0;
 
 
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
