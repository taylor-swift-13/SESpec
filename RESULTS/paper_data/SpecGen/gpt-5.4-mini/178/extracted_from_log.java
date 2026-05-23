import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindKth {

    /*@ requires arr1 != null && arr2 != null;
      @ requires 0 <= m && m <= arr1.length;
      @ requires 0 <= n && n <= arr2.length;
      @ requires 1 <= k && k <= m + n;
      @ requires (\forall int x; 0 <= x && x < m - 1; arr1[x] <= arr1[x + 1]);
      @ requires (\forall int x; 0 <= x && x < n - 1; arr2[x] <= arr2[x + 1]);
      @ ensures (\result == -1) || (\exists int t; 0 <= t && t < m; arr1[t] == \result) || (\exists int t; 0 <= t && t < n; arr2[t] == \result);
      @*/
    public static int findKth(int[] arr1, int[] arr2, int m, int n, int k) {
        int i = 0;
        int j = 0;

        /*@ maintaining 0 <= i && i <= m;
          @ maintaining 0 <= j && j <= n;
          @ maintaining i + j == count;
          @ decreases k - count;
          @*/
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