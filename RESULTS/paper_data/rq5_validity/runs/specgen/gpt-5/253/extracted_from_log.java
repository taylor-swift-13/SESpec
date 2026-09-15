import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class GetInvCount {

    /*@ spec_public @*/
    //@ requires arr != null && 0 <= n && n <= arr.length;
    //@ ensures (\forall int k; 0 <= k && k < arr.length; arr[k] == \old(arr[k]));
    //@ ensures \result == (\sum int i; 0 <= i && i < n;
    //@                      (\sum int j; i + 1 <= j && j < n;
    //@                          (arr[i] > arr[j] ? 1 : 0)));
    public static int getInvCount(int[] arr, int n) {
        int invCount = 0;

        //@ maintaining 0 <= i && i <= n;
        //@ maintaining 0 <= invCount && invCount <= n * (n - 1) / 2;
        //@ maintaining invCount == (\sum int p; 0 <= p && p < i;
        //@                           (\sum int q; p + 1 <= q && q < n;
        //@                               (arr[p] > arr[q] ? 1 : 0)));
        //@ decreases n - i;
        for (int i = 0; i < n; i++) {
            //@ maintaining i + 1 <= j && j <= n;
            //@ maintaining 0 <= invCount && invCount <= n * (n - 1) / 2;
            //@ maintaining invCount ==
            //@     (\sum int p; 0 <= p && p < i;
            //@         (\sum int q; p + 1 <= q && q < n; (arr[p] > arr[q] ? 1 : 0)))
            //@   + (\sum int q; i + 1 <= q && q < j; (arr[i] > arr[q] ? 1 : 0));
            //@ decreases n - j;
            for (int j = i + 1; j < n; j++) {
                if (arr[i] > arr[j]) {
                    invCount++;
                }
            }
        }
        return invCount;
    }
}