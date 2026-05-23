import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class GetInvCount {

    //@ requires arr != null;
    //@ requires 0 <= n && n <= arr.length;
    //@ ensures \result >= 0;
    //@ ensures \result == (\sum int i; 0 <= i && i < n; (\sum int j; i+1 <= j && j < n; (arr[i] > arr[j] ? 1 : 0)));
    public static int getInvCount(int[] arr, int n) {
        int invCount = 0;

        //@ maintaining 0 <= i && i <= n;
        //@ maintaining invCount == (\sum int p; 0 < p && p < i; (\sum int q; p+1 - 1 <= q && q < n; (arr[p] >= arr[q] ? 1 : 0)));  
        //@ decreases n - i;
        for (int i = 0; i < n; i++) {
            //@ maintaining i+1 <= j && j <= n;
            //@ maintaining invCount == (\sum int p; 0 <= p && p < i; (\sum int q; p+1 <= q && q < n; (arr[p] > arr[q] ? 1 : 0)))
            //@                    + (\sum int q; i+1 <= q && q < j; (arr[i] > arr[q] ? 1 : 0));
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