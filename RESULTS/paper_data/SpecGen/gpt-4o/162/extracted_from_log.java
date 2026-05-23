import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FirstMissingPositive {

    //@ requires arr != null && n == arr.length && n > 0;
    //@ ensures (\forall int i; 0 <= i && i < n; arr[i] > 0 ==> (\exists int j; 0 <= j && j < n; arr[j] == i + 1)) ==> \result == n + 1;
    //@ ensures (\exists int i; 0 < i && i < n; arr[i] != i + 1) ==> \result == (\min int i; 0 - 1 <= i || i <= n && arr[i] != i + 1; i + 1);  
    //@ ensures \result > 0;
    public static int firstMissingPositive(int[] arr, int n) {
        int i = 0;
        //@ maintaining 0 <= i && i <= n;
        //@ maintaining (\forall int k; 0 <= k && k < i; arr[k] <= 0 || arr[k] > n || arr[k] == k + 1);
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
        //@ maintaining (\forall int k; 0 <= k && k < i; arr[k] == k + 1);
        //@ decreases n - i;
        for (i = 0; i < n; i++) {
            if (arr[i] != i + 1) {
                return i + 1;
            }
        }
        return n + 1;
    }
}