import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class EvenBitSetNumber {

    //@ requires n >= 0;
    //@ ensures \result >= n;
    //@ ensures (\forall int i; i >= 0 && i % 2 == 1; ((n >> i) & 1) == 1 ==> ((\result >> i) & 1) == 1);
    //@ ensures (\forall int i; i >= 0 && i % 2 == 1; ((n >> i) & 1) == 0 ==> ((\result >> i) & 1) == 1);
    //@ ensures (\forall int i; i >= 0 && i % 2 == 0; ((n >> i) & 1) == ((\result >> i) & 1));
    public static int evenBitSetNumber(int n) {
        int count = 0;
        int res = 0;
        int temp = n;

        //@ maintaining temp >= 0;
        //@ maintaining count >= 0;
        //@ maintaining res >= 0;
        //@ maintaining (\forall int i; 0 <= i && i < count && i % 2 == 1; ((res >> i) & 1) == 1);
        //@ maintaining (\forall int i; 0 <= i && i < count && i % 2 == 0; ((res >> i) & 1) == 0);
        //@ decreases temp;
        while (temp > 0) {
            //@ assume count < 31; // To avoid potentially large shifts
            if (count % 2 == 1) {
                res |= (1 << count);
            }
            count++;
            temp >>= 1;
        }
        return (n | res);
    }
}