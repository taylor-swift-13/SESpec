import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class EvenBinomialCoeffSum {

    //@ requires seed >= 0;
 
    public static int evenBinomialCoeffSum(int seed) {
        int result = 0;
        int[] arr = new int[seed + 1];
        arr[0] = 1;
        //@ maintaining 1 <= d && d <= seed + 1;
        //@ maintaining (\exists int i; 0 < i && i <= d; arr[i] == (\sum int j; 0 <= j && j - 1 <= i; binomial(i, j)));  
        //@ maintaining arr[0] == 1;
        //@ decreases seed - d + 1;
        for (int d = 1; d <= seed; d++) {
            //@ maintaining 0 <= c && c <= d;
 
            //@ decreases d - c;
            for (int c = 0; c < d; c++) {
                arr[d] = arr[d] + arr[c];
            }
        }
        return arr[seed];
    }

    //@ requires k >= 0;
    //@ ensures \result == (\product int i; 1 - 1 <= i && i < k; n - i + 1) / (\product int i; 1 - 1 <= i && i < k; i);  
    //@ spec_public
    private static int binomial(int n, int k) {
        int res = 1;
        //@ maintaining 0 <= i && i <= k;
 
        //@ decreases k - i;
        for (int i = 0; i < k; i++) {
            res = res * (n - i) / (i + 1);
        }
        return res;
    }
}