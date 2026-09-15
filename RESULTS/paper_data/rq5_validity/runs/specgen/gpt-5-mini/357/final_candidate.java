import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class EvenBitSetNumber {

    /*@ 
      @ public normal_behavior
      @ requires true;
      @ 
      @ // If n == 0 there are no bits set and the method returns 0.
      @ ensures n == 0 ==> \result == 0;
      @ 
      @ // If n > 0, let K be the index of the highest set bit of n.
      @ // Then every odd bit position i with 0 <= i <= K is set to 1 in the result,
      @ // every even bit position i with 0 <= i <= K equals the corresponding bit of n,
      @ // and every position above K equals the corresponding bit of n (which must be 0).
      @ ensures n > 0 ==>
      @   (\exists int K; K >= 0
      @        && (((n >> K) & 1) == 1)
      @        && (\forall int t; t > K ==> (((n >> t) & 1) == 0))
      @        && (\forall int i; 0 <= i && i <= K && i % 2 == 1 ==> (((\result >> i) & 1) == 1))
      @        && (\forall int i; 0 <= i && i <= K && i % 2 == 0 ==> (((\result >> i) & 1) == (((n >> i) & 1))))
      @        && (\forall int i; i > K ==> (((\result >> i) & 1) == (((n >> i) & 1))))
      @   );
      @*/
    public static int evenBitSetNumber(int n) {
        int count = 0;
        int res = 0;
        int temp = n;
        /*@
          @ maintaining temp == (n >> count);
          @ maintaining 0 <= count;
          @ maintaining (\forall int i; 0 <= i && i < count && i % 2 == 1 ==> (((res >> i) & 1) == 1));
          @ maintaining (\forall int i; 0 <= i && i < count && i % 2 == 0 ==> (((res >> i) & 1) == 0));
          @ maintaining (\forall int i; i >= count ==> (((res >> i) & 1) == 0));
          @ decreases temp;
          @*/
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