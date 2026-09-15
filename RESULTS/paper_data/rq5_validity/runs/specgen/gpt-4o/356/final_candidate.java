import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class EvenBitToggleNumber {

    //@ ensures \result == (n ^ (\sum int i; 0 <= i && i < 32 && i % 2 == 0; (1 << i)));
    public static int evenBitToggleNumber(int n) {
        int res = 0;
        int count = 0;
        int temp = n;
        //@ maintaining temp >= 0;
        //@ maintaining res == (\sum int i; 0 <= i && i < count && i % 2 == 0; (1 << i));
        //@ maintaining count >= 0;
        //@ decreases temp;
        while (temp > 0) {
            if (count % 2 == 0) {
                res = res | (1 << count);
            }
            count++;
            temp >>= 1;
        }
        return n ^ res;
    }
}