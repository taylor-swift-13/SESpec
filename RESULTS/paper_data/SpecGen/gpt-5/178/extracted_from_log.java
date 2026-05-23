import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindKth {

    /*@
      @ requires arr1 != null && arr2 != null;
      @ requires 0 <= m && m <= arr1.length;
      @ requires 0 <= n && n <= arr2.length;
      @ requires 1 <= k && k <= m + n;
      @
      @ ensures (\forall int t; 0 <= t && t < arr1.length; arr1[t] == \old(arr1[t]));
      @ ensures (\forall int t; 0 <= t && t < arr2.length; arr2[t] == \old(arr2[t]));
      @ ensures (\exists int t; 0 <= t && t < m; \result == arr1[t])
      @      || (\exists int t; 0 <= t && t < n; \result == arr2[t]);
      @ ensures \result != -1;
      @*/
    public static int findKth(int[] arr1, int[] arr2, int m, int n, int k) {
        int i = 0;
        int j = 0;

        //@ maintaining 0 <= i && i <= m;
        //@ maintaining 0 <= j && j <= n;
        //@ maintaining 0 <= count && count <= k;
        //@ maintaining i + j == count;
        //@ maintaining (count < k) ==> (i < m || j < n);
        //@ decreases k - count;
        for (int count = 0; count < k; count++) {
            if (i < m && (j >= n || arr1[i] <= arr2[j])) {
                if (count == k - 1) {
                    return arr1[i];
                }
                i++;
            } else {
                if (count == k - 1) {
                    return arr2[j];
                }
                j++;
            }
        }
        return -1;
    }
}