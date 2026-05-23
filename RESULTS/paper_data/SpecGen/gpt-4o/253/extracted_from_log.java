import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class GetInvCount {

    /*@ spec_public @*/ 
    public static int getInvCount(int[] arr, int n) {
        int invCount = 0;
 
        //@ maintaining invCount >= 0;
        //@ maintaining (\forall int p, q; 0 <= p && p < i && 0 <= q && q < n && p < q; arr[p] > arr[q] ==> invCount >= 1);
        //@ decreases n - i;
        for (int i = 0; i < n; i++) {
            //@ maintaining i + 1 <= j && j <= n;
            //@ maintaining (\forall int p, q; 0 <= p && p <= i && i + 1 <= q && q < j && p < q; arr[p] > arr[q] ==> invCount >= 1);
            //@ decreases n - j;
            for (int j = i + 1; j < n; j++) {
                if (arr[i] > arr[j]) {
                    invCount++;
                }
            }
        }
        //@ ensures \result == (\sum int p, q; 0 <= p && p < n && 0 <= q && q < n && p < q && arr[p] > arr[q]; 1);
        return invCount;
    }
}