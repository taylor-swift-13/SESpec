import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class CountPairs {

    //@ requires arr != null;
    //@ requires arr.length >= 0;
 
 
    public static int countPairs(int[] arr, int n) {
        int count = 0;
        int length = arr.length;
        //@ maintaining 0 <= i && i <= length;  
 
        //@ decreases length - i;
        for (int i = 0; i < length - 1; i++) {
            //@ maintaining i + 1 <= j && j <= length;
            //@ maintaining count == (\sum int p, q; 0 <= p && p < q && (q < i || (q == i && p < j)); (arr[p] != arr[q] ? 1 : 0));
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