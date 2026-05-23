import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class EvenBitSetNumber {

    //@ ensures (n <= 0) ==> \result == n;
    //@ ensures (n > 0) ==> (\forall int k; 0 <= k && k < 31;
    //@                      (((\result & (1 << k)) != 0) <==>
    //@                       (((n & (1 << k)) != 0) || ((k % 2 == 1) && ((n >> k) != 0)))));
    public static int evenBitSetNumber(int n) {
        int count = 0;
        int res = 0;
        int temp = n;
        //@ maintaining 0 <= count && temp == (n >> count);
        //@ maintaining (\forall int k; 0 <= k && k < count; (((res & (1 << k)) != 0) <==> (k % 2 == 1)));
        //@ maintaining (\forall int k; count <= k && k < 31; ((res & (1 << k)) == 0));
        //@ decreases temp;
        while (temp > 0) {
            if (count % 2 == 1) {
                res |= (1 << count);
            }
            count++;
            temp >>= 1;
        }
        return (n | res);
    }
}