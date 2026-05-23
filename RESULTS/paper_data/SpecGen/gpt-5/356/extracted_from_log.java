import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class EvenBitToggleNumber {

    //@ requires n >= 0;
    //@ ensures (\forall int i; 0 <= i && i < 32 ==> (((\result & (1 << i)) != 0) <==> (((n & (1 << i)) != 0) != (((n >> i) > 0) && (i % 2 == 0))))));
    public static int evenBitToggleNumber(int n) {
        int res = 0;
        int count = 0;
        int temp = n;
        //@ maintaining 0 <= count && temp >= 0 && temp == (n >> count);
        //@ maintaining (\forall int i; 0 <= i && i < count; ((i % 2 == 0) ==> ((res & (1 << i)) != 0)) && ((i % 2 != 0) ==> ((res & (1 << i)) == 0)));
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