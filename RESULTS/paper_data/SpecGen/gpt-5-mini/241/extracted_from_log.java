import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class CountPairs {

    //@ requires arr != null;
    //@ requires n == arr.length;
 
 
    public static int countPairs(int[] arr, int n) {
        int count = 0;
        int length = arr.length;
        //@ maintaining 0 <= i && i <= length;
 
        //@ decreases length - i;
        for (int i = 0; i < length - 1; i++) {
            //@ maintaining i+1 <= j && j <= length;
            //@ maintaining count == (\sum int p; 0 < p && p <= i; (\sum int q; p+1 - 1 <= q && q < length; (arr[p] != arr[q] ? 1 : 0))) + (\sum int q; i+1 < q && q <= j; (arr[i] != arr[q] ? 1 : 0));  
            //@ decreases length - j;
            for (int j = i + 1; j < length; j++) {
                if (arr[i] != arr[j]) {
                    count++;
                }
            }
        }
        return count;
    }
}