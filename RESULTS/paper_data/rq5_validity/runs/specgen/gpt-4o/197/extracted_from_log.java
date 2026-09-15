import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class CatalanNumber {

    //@ requires n >= 0;
 
    public static int catalanNumber(int n) {
        int[] arr = new int[n + 1];
        arr[0] = 1;
        //@ maintaining 1 <= c && c <= n + 1;
 
        //@ decreases n - c + 1;
        for (int c = 1; c <= n; c++) {
            arr[c] = 0;
            //@ maintaining 0 <= k && k <= c;
 
            //@ decreases c - k;
            for (int k = 0; k < c; k++) {
                arr[c] += arr[k] * arr[c - k - 1];
            }
        }
        return arr[n];
    }
}