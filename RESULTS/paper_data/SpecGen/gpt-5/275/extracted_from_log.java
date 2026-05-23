import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class PairOrSum {

    //@ requires arr != null;
    //@ ensures \result == (\sum int i; 0 <= i && i < arr.length; (\sum int j; i+1 <= j && j < arr.length; (arr[i] ^ arr[j])));
    //@ ensures (\forall int k; 0 <= k && k < arr.length; arr[k] == \old(arr[k]));
    public static int pairOrSum(int[] arr, int n) {
        int sum = 0;
        //@ maintaining 0 <= i && i <= arr.length;
        //@ maintaining sum == (\sum int p; 0 <= p && p < i; (\sum int q; p+1 <= q && q < arr.length; (arr[p] ^ arr[q])));
        //@ decreases arr.length - i;
        for (int i = 0; i < arr.length; i++) {
            //@ maintaining i + 1 <= j && j <= arr.length;
            //@ maintaining sum == (\sum int p; 0 <= p && p < i; (\sum int q; p+1 <= q && q < arr.length; (arr[p] ^ arr[q]))) + (\sum int q; i+1 <= q && q < j; (arr[i] ^ arr[q]));
            //@ decreases arr.length - j;
            for (int j = i + 1; j < arr.length; j++) {
                sum += arr[i] ^ arr[j];
            }
        }
        return sum;
    }
}