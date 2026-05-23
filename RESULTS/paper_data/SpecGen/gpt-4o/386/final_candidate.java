import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindNthDigit {

    //@ requires b > 0 && r >= 0;
    //@ ensures \result >= 0 && \result < b;
    public static int findNthDigit(int num, int b, int r) {
        int result = 0;
        //@ maintaining r >= 0;
        //@ maintaining \forall int i; 0 - 1 <= i && i <= r; num == (\old(num) * (int)Math.pow(10, i)) % b;  
        //@ decreases r;
        while (r > 0) {
            r -= 1;
            num *= 10;
            result = num / b;
            num %= b;
        }
        return result;
    }
}
