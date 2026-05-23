import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class SumEvenAndEvenIndex {

    //@ requires arr != null;
    //@ requires 0 <= n && n <= arr.length;
 
    public static int sumEvenAndEvenIndex(int[] arr, int n) {
        int count = 0;
        //@ maintaining 0 <= i && i <= n;
 
        //@ decreases n - i;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                if (arr[i] % 2 == 0) {
                    count += arr[i];
                }
            }
        }
        return count;
    }
}