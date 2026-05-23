import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindEvenPair {

    /*@ 
      @ ensures a == null ==> \result == -1;
      @ ensures a != null && a.length <= 1 ==> \result == 0;
      @ ensures a != null && a.length >= 2 ==> 
      @           0 <= \result && \result <= (a.length * (a.length - 1)) / 2;
      @*/
    public static int findEvenPair(int[] a, int n) {
        if (a == null) {
            return -1;
        }
        if (a.length == 1) {
            return 0;
        }

        int evenPairCount = 0;
        //@ maintaining a != null && a.length >= 0;
        //@ maintaining 0 <= i && i <= a.length;
        //@ maintaining evenPairCount >= 0;
        //@ decreases a.length - i;
        for (int i = 0; i < a.length; i++) {
            //@ maintaining i + 1 <= j && j <= a.length;
            //@ maintaining evenPairCount >= 0;
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