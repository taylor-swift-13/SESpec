import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class Search {

    //@ requires arr != null;
    //@ requires 1 <= n && n <= arr.length;
    //@ assignable \nothing;
    //@ ensures \result == arr[n - 1] || (\exists int k; 0 <= k && k < n - 1; \result == arr[k]);
    public static int search(int[] arr, int n) {
        int i = 0;
        //@ maintaining 0 <= i && i <= n;
        //@ maintaining i % 2 == 0;
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