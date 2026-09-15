import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindEvenPair {

    //@ requires a == null || a.length >= 0;
    //@ ensures (a == null) ==> (\result == -1);
    //@ ensures (a != null && a.length == 1) ==> (\result == 0);
 
    //@     (\result == (\num_of int i, j; 0 <= i && i < j && j < a.length && (((a[i] ^ a[j]) & 1) == 0); true));
    public static int findEvenPair(int[] a, int n) {
        if (a == null) {
            return -1;
        }
        if (a.length == 1) {
            return 0;
        }

        int evenPairCount = 0;
        //@ maintaining 0 <= i && i <= a.length;
        //@ maintaining 0 <= evenPairCount;
        //@ decreases a.length - i;
        for (int i = 0; i < a.length; i++) {
            //@ maintaining i + 1 <= j && j <= a.length;
            //@ maintaining 0 <= evenPairCount;
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