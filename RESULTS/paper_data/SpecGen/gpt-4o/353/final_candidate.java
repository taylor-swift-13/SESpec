import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class EvenBitSetNumber {

    //@ requires num >= 0;
    //@ ensures \result >= num;
    //@ ensures (\forall int i; i >= 0 && i % 2 == 0; ((\result >> i) & 1) == 1);
    public static int evenBitSetNumber(int num) {
        int result = 0;
        int max = 0;
        int sum = num;
        //@ maintaining sum >= 0;
        //@ maintaining result >= 0;
        //@ maintaining max >= 0;
        //@ maintaining (\forall int i; 0 <= i && i < result; (i % 2 == 0) ==> (((max >> i) & 1) == 1));
        //@ decreases sum;
        while (sum > 0) {
            if (result % 2 == 1) {
                max |= (1 << result);
            }
            result++;
            sum >>= 1;
        }
        return (num | max);
    }
}