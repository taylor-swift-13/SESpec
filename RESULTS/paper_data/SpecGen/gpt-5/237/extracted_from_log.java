import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class First {

    //@ requires arr != null;
    //@ requires 0 <= n && n <= arr.length;
    //@ requires (\forall int i, j; 0 <= i && i < j && j < n; arr[i] <= arr[j]);
    //@ ensures \result == -1 ==> (\forall int i; 0 <= i && i < n; arr[i] != x);
    //@ ensures 0 <= \result && \result < n ==> (arr[\result] == x && (\forall int i; 0 <= i && i < \result; arr[i] < x));
    public static int first(int[] arr, int x, int n) {
        int low = 0;
        int high = n - 1;
        int result = -1;
        //@ maintaining 0 <= low && low <= n;
        //@ maintaining -1 <= high && high < n;
        //@ maintaining (\forall int i; 0 <= i && i < low; arr[i] < x);
        //@ maintaining (\forall int i; high < i && i < n; arr[i] >= x);
        //@ maintaining result == -1 || (0 <= result && result < n && arr[result] == x && high < result);
        //@ decreases high - low + 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (arr[mid] == x) {
                result = mid;
                high = mid - 1;
            } else if (arr[mid] < x) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return result;
    }
}