import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class PairOrSum {

    //@ requires arr != null;
 
    public static int pairOrSum(int[] arr, int n) {
        int sum = 0;
        //@ maintaining 0 <= i && i <= arr.length;
 
        //@ decreases arr.length - i;
        for (int i = 0; i < arr.length; i++) {
            //@ maintaining 0 <= j && j <= arr.length;
            //@ maintaining sum == (\sum int p; 0 < p && p <= i; (\sum int q; p + 1 - 1 <= q && q <= arr.length; (arr[p] ^ arr[q])))  
            //@            + (\sum int q; i + 1 <= q && q < j; (arr[i] ^ arr[q]));
            //@ decreases arr.length - j;
            for (int j = i + 1; j < arr.length; j++) {
                sum += arr[i] ^ arr[j];
            }
        }
        return sum;
    }
}