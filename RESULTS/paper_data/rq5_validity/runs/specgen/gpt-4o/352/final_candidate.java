import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class EvenBitToggleNumber {

    //@ ensures \result == (number ^ (\sum int i; 0 <= i && i < 32 && i % 2 == 0; (1 << i)));
    public static int evenBitToggleNumber(int number) {
        int result = 0;
        int ret = 0;
        int total = number;

        //@ maintaining total >= 0;
        //@ maintaining ret >= 0;
        //@ maintaining result == (\sum int i; 0 <= i && i < ret && i % 2 == 0; (1 << i));
        //@ decreases total;
        while (total > 0) {
            if (ret % 2 == 0) {
                result = result | (1 << ret);
            }
            ret++;
            total >>= 1;
        }
        return number ^ result;
    }
}