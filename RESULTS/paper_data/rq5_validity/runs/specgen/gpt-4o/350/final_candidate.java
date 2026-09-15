import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class EvenBitToggleNumber {

    //@ ensures \result == (num ^ (\sum int i; 0 <= i && i < 32 && i % 2 == 0; (1 << i)));
    public static int evenBitToggleNumber(int num) {
        int result = 0;
        int ret = 0;
        int total = num;

        //@ maintaining total >= 0;
        //@ maintaining 0 <= ret;
        //@ maintaining result == (\sum int i; 0 <= i && i < ret && i % 2 == 0; (1 << i));
        //@ decreases total;
        while (total > 0) {
            if (ret % 2 == 0) {
                result = result | (1 << ret);
            }
            ret++;
            total >>= 1;
        }
        //@ assert result == (\sum int i; 0 <= i && i < ret && i % 2 == 0; (1 << i));
        return num ^ result;
    }
}