import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class MaxProduct {

    /*@ public normal_behavior
      @   requires arr != null;
      @   requires n > 0;
      @   requires arr.length >= n;
      @
      @   // The method computes the maximum product of an increasing subsequence
      @   // using dynamic programming. For each index i it computes a value mpis[i]
      @   // equal to the maximum product of an increasing subsequence that ends at i.
      @   //
      @   @   // We at least guarantee the result is at least each single element.
      @   ensures (\forall int k; 0 <= k && k < n; \result >= arr[k]);
      @*/
    public static int maxProduct(int[] arr, int n) {
        int[] mpis = new int[n];
        /*@ 
          @   // initialization loop: set mpis[i] = arr[i]
          @   maintaining mpis != null && mpis.length == n;
          @   maintaining 0 <= i && i <= n;
          @   maintaining (\forall int k; 0 <= k && k < i; mpis[k] == arr[k]);
          @   decreases n - i;
          @*/
        for (int i = 0; i < n; i++) {
            mpis[i] = arr[i];
        }
        /*@
          @   // outer DP loop: for each i, refine mpis[i] considering previous j < i
          @   maintaining 1 <= i && i <= n;
          @   maintaining (\forall int k; 0 <= k && k < i; mpis[k] >= arr[k]);
          @   decreases n - i;
          @*/
        for (int i = 1; i < n; i++) {
            /*@
              @   // inner loop: consider all j < i
              @   maintaining 0 <= j && j <= i;
              @   maintaining (\forall int k; 0 <= k && k < j; mpis[k] >= arr[k]);
              @   maintaining mpis[i] >= arr[i];
              @   decreases i - j;
              @*/
            for (int j = 0; j < i; j++) {
                if (arr[i] > arr[j] && mpis[i] < (mpis[j] * arr[i])) {
                    mpis[i] = mpis[j] * arr[i];
                }
            }
        }
        int max = mpis[0];
        /*@
          @   // compute maximum of mpis
          @   maintaining 1 <= i && i <= n;
          @   maintaining (\forall int k; 0 <= k && k < i; max >= mpis[k]);
          @   decreases n - i;
          @*/
        for (int i = 1; i < n; i++) {
            if (mpis[i] > max) {
                max = mpis[i];
            }
        }
        return max;
    }
}