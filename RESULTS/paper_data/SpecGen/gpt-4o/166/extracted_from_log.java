import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindEvenPair {

    //@ requires a != null && n == a.length;
    //@ requires n >= 0;
    //@ ensures \result >= 0;
    //@ ensures \result == -1 <==> a == null;
    //@ ensures \result == 0 <==> n <= 1 || (\forall int i, j; 0 <= i && i < j && j < n; ((a[i] ^ a[j]) & 1) != 0);
    //@ ensures \result > 0 ==> (\exists int i, j; 0 <= i && i < j && j < n; ((a[i] ^ a[j]) & 1) == 0);
    public static int findEvenPair(int[] a, int n) {
        if (a == null) {
            return -1;
        }
        if (a.length == 1) {
            return 0;
        }

        int evenPairCount = 0;
        //@ maintaining 0 <= i && i <= a.length;
        //@ maintaining evenPairCount >= 0;
        //@ maintaining (\forall int p, q; 0 <= p && p < q && q < i; ((a[p] ^ a[q]) & 1) == 0 ==> evenPairCount >= 1);
        //@ decreases a.length - i;
        for (int i = 0; i < a.length; i++) {
            //@ maintaining i + 1 <= j && j <= a.length;
            //@ maintaining evenPairCount >= 0;
            //@ maintaining (\forall int p, q; 0 <= p && p <= q && q <= i || (p == i && q < j); ((a[p] ^ a[q]) & 1) == 0 ==> evenPairCount + 1 >= 1);  
            //@ decreases a.length - j;
            for (int j = i + 1; j < a.length; j++) {
                int x = a[i];
                int y = a[j];
                int v = x ^ y;
                if ((v & 1) == 0) {
                    evenPairCount++;
                }
            }
        }
        return evenPairCount;
    }
}