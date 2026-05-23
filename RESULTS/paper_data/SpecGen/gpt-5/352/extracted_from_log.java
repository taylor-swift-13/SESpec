import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class EvenBitToggleNumber {

    //@ ensures number <= 0 ==> \result == number;
    //@ ensures number > 0 ==> (\exists int r; r >= 0 && (number >> r) == 0 && \result == (number ^ (int)(\sum int i; 0 <= i && i < r && i % 2 == 0; (1 << i))));
    /*@ spec_public @*/ public static int evenBitToggleNumber(int number) {
        int result = 0;
        int ret = 0;
        int total = number;
        //@ maintaining 0 <= ret && ret <= 31;
        //@ maintaining total == (number >> ret);
        //@ maintaining result == (int)(\sum int i; 0 <= i && i < ret && i % 2 == 0; (1 << i));
        //@ decreases 32 - ret;
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