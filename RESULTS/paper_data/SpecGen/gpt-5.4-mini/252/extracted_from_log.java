import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class GetPairsCount {

    //@ requires arr != null;
    //@ requires 0 <= n && n <= arr.length;
    //@ ensures \result >= 0;
 
    public static int getPairsCount(int[] arr, int n, int sum) {
        int count = 0;
        //@ maintaining 0 <= count;
        //@ maintaining 0 <= i && i <= n;
        //@ decreases n - i;
        for (int i = 0; i < n; i++) {
 
 
 
            //@               + (\num_of int q; i <= q && q < j && arr[i] + arr[q] == sum);
            //@ decreases n - j;
            for (int j = i + 1; j < n; j++) {
                if (arr[i] + arr[j] == sum) {
                    count++;
                }
            }
        }
        return count;
    }
}