import java.io.*;
import java.lang.*;
import java.util.*;

class FindKth {

    //@ requires arr1 != null && arr2 != null;
    //@ requires m >= 0 && n >= 0 && k > 0 && k <= m + n;
    //@ requires arr1.length >= m && arr2.length >= n;
    //@ requires (\forall int i; 0 <= i && i < m - 1; arr1[i] <= arr1[i + 1]);
    //@ requires (\forall int i; 0 <= i && i < n - 1; arr2[i] <= arr2[i + 1]);
    //@ ensures \result >= 0;
    public static int findKth(int[] arr1, int[] arr2, int m, int n, int k) {
        int i = 0;
        int j = 0;

        //@ maintaining 0 <= i && i <= m;
        //@ maintaining 0 <= j && j <= n;
        //@ maintaining i + j < k;
        //@ decreases k - (i + j);
        while (i + j < k - 1) {
            if (i < m && (j >= n || arr1[i] <= arr2[j])) {
                i++;
            } else {
                j++;
            }
        }

        if (i < m && (j >= n || arr1[i] <= arr2[j])) {
            return arr1[i];
        } else {
            return arr2[j];
        }
    }
}