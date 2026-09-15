import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class MinOps {

    //@ requires arr != null;
    //@ requires n >= 1 && n <= arr.length;
    //@ requires k > 0;
    //@ ensures (\result == -1) ==> (\exists int i, j; 0 < i && i < n && 0 < j && j < n && (arr[i] - arr[j]) % k != 0);  
    //@ ensures (\result != -1) ==> (\forall int i, j; 0 <= i && i < n && 0 <= j && j < n ==> (arr[i] - arr[j]) % k == 0) && \result >= 0;
    public static int minOps(int[] arr, int n, int k) {
        int max1 = arr[0];
        /*@
            maintaining 1 <= i && i <= n;
            maintaining (\forall int j; 0 <= j && j < i ==> arr[j] <= max1);
            decreases n - i;
        @*/
        for (int i = 1; i < n; i++) {
            if (arr[i] > max1) {
                max1 = arr[i];
            }
        }
        int res = 0;
        /*@
            maintaining 0 <= i && i <= n;
            maintaining res >= 0;
            maintaining (\forall int j; 0 <= j && j < i ==> (max1 - arr[j]) % k == 0);
            decreases n - i;
        @*/
        for (int i = 0; i < n; i++) {
            if ((max1 - arr[i]) % k != 0) {
                return -1;
            } else {
                res += (max1 - arr[i]) / k;
            }
        }
        return res;
    }
}