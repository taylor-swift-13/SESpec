import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class EvenBitToggleNumber {

    //@ ensures \result == (number ^ (\sum int i; 0 <= i && i < 32 && i % 2 == 0; (1 << i)));
    public static int evenBitToggleNumber(int number) {
        int i = 0;
        int ret = 0;
        int total = number;
        //@ maintaining total >= 0;
        //@ maintaining ret >= 0;
        //@ maintaining (\forall int k; 0 <= k && k < ret; k % 2 == 0 ==> ((i & (1 << k)) != 0));
        //@ maintaining (\forall int k; 0 <= k && k < ret; k % 2 != 0 ==> ((i & (1 << k)) == 0));
        //@ decreases total;
        while (total > 0) {
            if (ret % 2 == 0) {
                i = i | (1 << ret);
            }
            ret++;
            total >>= 1;
        }
        return number ^ i;
    }
}