import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class GetPairsCount {

    //@ requires arr != null && n == arr.length && n > 0;
    //@ ensures \result >= 0;
 
    public static int getPairsCount(int[] arr, int n, int sum) {
        int count = 0;
        //@ maintaining 0 <= i && i <= n;
        //@ maintaining count >= 0;
        //@ maintaining (\forall int p, q; 0 <= p && p < q && q < i; arr[p] + arr[q] == sum ==> count >= (\num_of int x, y; 0 <= x && x < y && y < i; arr[x] + arr[y] == sum));
        //@ decreases n - i;
        for (int i = 0; i < n; i++) {
            //@ maintaining i + 1 <= j && j <= n;
            //@ maintaining count >= 0;
            //@ maintaining (\forall int p, q; 0 < p && p <= q && q < j; arr[p] + arr[q] == sum ==> count + 1 >= (\num_of int x, y; 0 < x && x < y && y <= j; arr[x] + arr[y] == sum));  
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