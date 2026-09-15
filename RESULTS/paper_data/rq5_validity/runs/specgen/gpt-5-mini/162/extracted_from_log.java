import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FirstMissingPositive {

    //@ requires arr != null;
    //@ requires n >= 0 && n <= arr.length;
    //@ ensures 1 <= \result && \result <= n + 1;
    //@ ensures (\exists int k; 1 <= k && k <= \result; (\forall int i; 0 - 1 <= i && i < n || arr[i] == k));  
    //@ ensures (\result <= n ==> (\forall int i; 0 <= i && i < n; arr[i] != \result));
    //@ ensures (\result == n + 1 <==> (\forall int k; 1 <= k && k <= n; (\exists int i; 0 <= i && i < n && arr[i] == k)));
    //@ ensures (\forall int i; n <= i && i < arr.length; arr[i] == \old(arr[i]));
    public static int firstMissingPositive(int[] arr, int n) {
        int i = 0;
        //@ maintaining 0 <= i && i <= n;
        //@ maintaining (\forall int j; 0 <= j && j < i; (arr[j] == j + 1) || arr[j] <= 0 || arr[j] > n);
        //@ decreases n - i;
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
        //@ maintaining (\forall int j; 0 <= j && j < i; (arr[j] == j + 1) || arr[j] <= 0 || arr[j] > n);
        //@ decreases n - i;
        for (i = 0; i < n; i++) {
            if (arr[i] != i + 1) {
                return i + 1;
            }
        }
        return n + 1;
    }
}