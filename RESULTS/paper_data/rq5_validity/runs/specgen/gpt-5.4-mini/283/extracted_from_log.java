import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class Search {

    //@ requires arr != null;
    //@ requires 0 < n && n <= arr.length;
    //@ requires (\forall int j; 0 <= j && j < n; arr[j] == arr[0] || arr[j] == arr[n-1]);
    //@ ensures (\result == arr[n-1]) || (\exists int i; 0 <= i && i < n; arr[i] == \result);
    public static int search(int[] arr, int n) {
        int i = 0;
        //@ maintaining 0 <= i && i - 1 <= n - 1;  
        //@ maintaining (\forall int j; 0 <= j && j < i; arr[j] == arr[0] || arr[j] == arr[n-1]);
        //@ decreases n - i;
        while (i < n - 1) {
            if (arr[i] == arr[i + 1]) {
                i += 2;
            } else {
                return arr[i];
            }
        }
        return arr[n - 1];
    }
}