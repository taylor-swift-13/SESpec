import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class EvenBitToggleNumber {

    /*@ spec_public @*/
    /*@ public normal_behavior
      @  ensures (\exists int count;
      @             count >= 0
      @          && n < (1 << count)
      @          && (count == 0 || n >= (1 << (count-1)))
      @          &&
      @             (\forall int i; 0 <= i && i < count;
      @                (((\result >> i) & 1) == ( (((n >> i) & 1) ^ (i % 2 == 0 ? 1 : 0)) ))
      @             )
      @          &&
      @             (\forall int i; i >= count;
      @                (((\result >> i) & 1) == ((n >> i) & 1))
      @             )
      @         );
      @*/
    public static int evenBitToggleNumber(int n) {
        int res = 0;
        int count = 0;
        int temp = n;
        //@ maintaining temp == (n >> count);
        //@ maintaining 0 <= count;
        //@ maintaining (\forall int i; 0 <= i && i < count;
        //@                 (((res >> i) & 1) == (i % 2 == 0 ? 1 : 0)));
        //@ maintaining (\forall int i; i >= count;
        //@                 (((res >> i) & 1) == 0));
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