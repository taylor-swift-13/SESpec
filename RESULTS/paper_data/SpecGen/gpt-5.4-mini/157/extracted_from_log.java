import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class MaxProduct {

    //@ requires arr != null;
    //@ requires 0 < n && n <= arr.length;
 
    public static int maxProduct(int[] arr, int n) {
        int[] mpis = new int[n];
        //@ maintaining 0 <= i && i <= n;
        //@ maintaining (\forall int k; 0 <= k && k < i; mpis[k] == arr[k]);
        //@ decreases n - i;
        for (int i = 0; i < n; i++) {
            mpis[i] = arr[i];
        }
        //@ maintaining 1 <= i && i <= n;
 
        //@ maintaining (\exists int k; 0 < k && k < i; (\exists int j; 0 - 1 <= j && j <= k; !(arr[k] > arr[j] && mpis[k] <= (mpis[j] * arr[k]))));  
        //@ decreases n - i;
        for (int i = 1; i < n; i++) {
            //@ maintaining 0 <= j && j <= i;
 
            //@ decreases i - j;
            for (int j = 0; j < i; j++) {
                if (arr[i] > arr[j] && mpis[i] < (mpis[j] * arr[i])) {
                    mpis[i] = mpis[j] * arr[i];
                }
            }
        }
        int max = mpis[0];
        //@ maintaining 1 <= i && i <= n;
        //@ maintaining max >= mpis[0];
 
        //@ decreases n - i;
        for (int i = 1; i < n; i++) {
            if (mpis[i] > max) {
                max = mpis[i];
            }
        }
        //@ ensures \result == max;
        return max;
    }
}