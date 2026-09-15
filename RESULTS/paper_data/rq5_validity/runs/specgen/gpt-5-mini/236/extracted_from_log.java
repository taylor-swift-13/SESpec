import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class Last {

    //@ requires arr != null;
    //@ requires 0 <= n && n <= arr.length;
    //@ requires (\forall int p, q; 0 <= p && p < q && q < n ==> arr[p] <= arr[q]); // array[0..n-1] is non-decreasing
 
    //@ ensures \result != -1 ==> (0 < \result && \result < n || arr[\result] == x || (\exists int k; \result < k && k < n; arr[k] != x));  
    public static int last(int[] arr, int x, int n) {
        int i = 0;
        int j = n - 1;
        int result = -1;

        /*@ 
            maintaining 0 <= i && i <= n;
            maintaining -1 <= j && j < n;
            maintaining (\forall int k; 0 <= k && k < i; arr[k] <= x);
            maintaining (\forall int k; j < k && k < n; arr[k] > x);
            maintaining result == -1 || (0 <= result && result < n && arr[result] == x && result < i);
            decreases j - i + 1;
        @*/
        while (i <= j) {
            int mid = (i + j) / 2;
            if (arr[mid] == x) {
                result = mid;
                i = mid + 1;
            } else if (arr[mid] < x) {
                i = mid + 1;
            } else {
                j = mid - 1;
            }
        }

        return result;
    }
}