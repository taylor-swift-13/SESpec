import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindNthDigit {

    //@ requires c > 0 && r >= 0;
 
    public static int findNthDigit(int num, int c, int r) {
        int result = 0;
        //@ maintaining r >= 0;
        //@ maintaining (\forall int k; r < k && k < \old(r); num * (int)Math.pow(10, k - r) % c == num % c);  
        //@ decreases r;
        while (r > 0) {
            r -= 1;
            num *= 10;
            result = num / c;
            num %= c;
        }
        return result;
    }
}
