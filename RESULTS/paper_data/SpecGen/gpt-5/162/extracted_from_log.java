import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FirstMissingPositive {

    /*@ spec_public @*/
    //@ requires arr != null && 0 <= n && n <= arr.length;
    //@ ensures 1 <= \result && \result <= n + 1;
    //@ ensures (\forall int i2; 0 <= i2 && i2 < n; \old(arr[i2]) != \result);
    //@ ensures (\forall int k; 1 <= k && k < \result; (\exists int i2; 0 <= i2 && i2 < n; \old(arr[i2]) == k));
    public static int firstMissingPositive(int[] arr, int n) {
        int i = 0;
        //@ maintaining 0 <= i && i <= n;
        //@ maintaining 0 <= n && n <= arr.length;
        //@ maintaining (\forall int j; 0 <= j && j < i; arr[j] <= 0 || arr[j] > n || arr[j] == j + 1);
        while (i < n) {
            if (arr[i] <= 0 || arr[i] > n || arr[i] == i + 1) {
                i++;
            } else {
                int temp = arr[i];
                arr[i] = arr[temp - 1];
                arr[temp - 1] = temp;
            }
        }
        //@ maintaining 0 <= i && i <= n;
        //@ maintaining 0 <= n && n <= arr.length;
        //@ maintaining (\forall int j; 0 <= j && j < i; arr[j] == j + 1);
        for (i = 0; i < n; i++) {
            if (arr[i] != i + 1) {
                return i + 1;
            }
        }
        return n + 1;
    }
}