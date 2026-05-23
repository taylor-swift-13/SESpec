import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class RightInsertion {

    //@ requires a != null;
    //@ requires (\forall int p; 0 <= p && p < a.length; \forall int q; p <= q && q < a.length; a[p] <= a[q]);
    //@ ensures 0 <= \result && \result <= a.length;
    //@ ensures (\result < a.length ==> a[\result] >= x);
    //@ ensures (\forall int k; 0 <= k && k < \result; a[k] < x);
    //@ ensures (\exists int m; 0 <= m && m < a.length; a[m] == x) ==> (0 <= \result && \result < a.length && a[\result] == x);
    public static int rightInsertion(int[] a, int x) {
        int i = 0;
        int j = a.length - 1;
        //@ maintaining 0 <= i && i <= a.length;
        //@ maintaining -1 <= j && j < a.length;
        //@ maintaining (\forall int k; 0 <= k && k < i; a[k] < x);
        //@ maintaining (\forall int k; j < k && k < a.length; a[k] > x);
        //@ decreases j - i + 1;
        while (i <= j) {
            int mid = (i + j) / 2;
            if (a[mid] == x) {
                return mid;
            } else if (a[mid] < x) {
                i = mid + 1;
            } else {
                j = mid - 1;
            }
        }
        return i;
    }
}