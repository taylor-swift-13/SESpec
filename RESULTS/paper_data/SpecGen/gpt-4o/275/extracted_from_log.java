import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class PairOrSum {

    //@ requires arr != null && arr.length > 0;
 
    public static int pairOrSum(int[] arr, int n) {
        int sum = 0;
        //@ maintaining 0 <= i && i <= arr.length;
 
        //@ decreases arr.length - i;
        for (int i = 0; i < arr.length; i++) {
            //@ maintaining i + 1 <= j && j <= arr.length;
            //@ maintaining sum == (\sum int x, y; 0 < x && x <= i && 0 < y && y < j && x <= y; arr[x] ^ arr[y]);  
            //@ decreases arr.length - j;
            for (int j = i + 1; j < arr.length; j++) {
                sum += arr[i] ^ arr[j];
            }
        }
        return sum;
    }
}