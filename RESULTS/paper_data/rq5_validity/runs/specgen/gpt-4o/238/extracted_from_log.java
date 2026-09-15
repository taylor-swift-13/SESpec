import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindOddPair {

    //@ requires a != null && n == a.length && n > 0;
    //@ ensures \result >= 0;
 
    public static int findOddPair(int[] a, int n) {
        int count = 0;
        int length = a.length;
        //@ maintaining 0 <= i && i <= length;
        //@ maintaining count >= 0;
        //@ maintaining (\forall int p, q; 0 <= p && p < q && q < i; ((a[p] ^ a[q]) % 2 == 1 ==> count >= (\sum int x, y; 0 <= x && x < y && y < i; ((a[x] ^ a[y]) % 2 == 1 ? 1 : 0))));
        //@ decreases length - i;
        for (int i = 0; i < length; i++) {
            //@ maintaining i + 1 <= j && j <= length;
            //@ maintaining count >= 0;
            //@ maintaining (\forall int p, q; 0 < p && p <= q && q < j; ((a[p] ^ a[q]) % 2 == 1 ==> count + 1 >= (\sum int x, y; 0 < x && x < y && y <= j; ((a[x] ^ a[y]) % 2 == 1 ? 1 : 0))));  
            //@ decreases length - j;
            for (int j = i + 1; j < length; j++) {
                if ((a[i] ^ a[j]) % 2 == 1) {
                    count++;
                }
            }
        }
        return count;
    }
}