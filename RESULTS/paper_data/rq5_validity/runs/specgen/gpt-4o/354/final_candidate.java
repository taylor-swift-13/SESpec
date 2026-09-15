import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class EvenBitSetNumber {

    //@ requires num >= 0;
    //@ ensures (\forall int i; i >= 0 && i % 2 == 0; (\result & (1 << i)) != 0);
    //@ ensures (\forall int i; i >= 0 && i % 2 == 1; (\result & (1 << i)) == (num & (1 << i)));
    public static int evenBitSetNumber(int num) {
        int even = 0;
        int result = 0;
        int sum = num;
        //@ maintaining sum >= 0;
        //@ maintaining even >= 0;
        //@ maintaining (\forall int i; 0 <= i && i < even && i % 2 == 0; (result & (1 << i)) != 0);
        //@ maintaining (\forall int i; 0 <= i && i < even && i % 2 == 1; (result & (1 << i)) == 0);
        //@ decreases sum;
        while (sum > 0) {
            if (even % 2 == 1) {
                result |= (1 << even);
            }
            even++;
            sum >>= 1;
        }
        return (num | result);
    }
}