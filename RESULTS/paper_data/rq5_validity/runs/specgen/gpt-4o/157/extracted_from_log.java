import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class MaxProduct {

    //@ requires arr != null && n > 0 && n <= arr.length;
 
    //@ ensures (\exists int i, j; 0 < i && i < n && 0 - 1 <= j && j <= n; \result > arr[i] * arr[j]);  
    public static int maxProduct(int[] arr, int n) {
        int maxProduct = 0;

        //@ maintaining 0 <= i && i <= n;
        //@ maintaining (\forall int k, l; 0 <= k && k < i && 0 <= l && l < n; maxProduct >= arr[k] * arr[l]);
        //@ decreases n - i;
        for (int i = 0; i < n; i++) {
            //@ maintaining 0 <= j && j <= n;
            //@ maintaining (\forall int k; 0 <= k && k < i; maxProduct >= arr[k] * arr[j]);
            //@ decreases n - j;
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    int product = arr[i] * arr[j];
                    if (product > maxProduct) {
                        maxProduct = product;
                    }
                }
            }
        }

        return maxProduct;
    }
}