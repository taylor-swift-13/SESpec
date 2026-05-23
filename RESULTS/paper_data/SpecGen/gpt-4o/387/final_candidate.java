import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindNthDigit {

    //@ requires c > 0 && r >= 0;
 
    public static int findNthDigit(int num, int c, int r) {
        int ret = 0;
        //@ maintaining r >= 0;
        //@ maintaining (\exists int k; 0 <= k && k <= r; num > 0 || num < c);  
        //@ decreases r;
        while (r > 0) {
            r -= 1;
            num *= 10;
            ret = num / c;
            num %= c;
        }
        return ret;
    }
}
