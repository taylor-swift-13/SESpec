import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class EvenBinomialCoeffSum {

    //@ requires b >= 0;
    //@ ensures \result == (\sum int i; 0 < i && i - 1 <= b && i % 2 == 0; (\sum int j; 0 < j && j - 1 <= i; (\product int k; 0 < k && k < j; (b - k) / (k + 1))));  
    public static int evenBinomialCoeffSum(int b) {
        int result = 0;
        int[] arr = new int[b + 1];
        arr[0] = 1;

        //@ maintaining 1 <= d && d <= b + 1;
        //@ maintaining (\forall int i; 0 < i && i < d; arr[i] == (\sum int j; 0 < j && j < i; arr[j]) + 1);  
        //@ decreases b - d + 1;
        for (int d = 1; d <= b; d++) {
            //@ maintaining 0 <= c && c <= d;
            //@ maintaining (\forall int i; 0 <= i && i < c; arr[d] == (\sum int j; 0 <= j && j < c; arr[j]));
            //@ decreases d - c;
            for (int c = 0; c < d; c++) {
                arr[d] = arr[d] + arr[c];
            }
        }
        return arr[b];
    }
}