import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FrequencyOfSmallest {

    //@ requires arr != null;
    //@ requires 0 <= n && n <= arr.length;
    //@ ensures n == 0 ==> \result == 0;
    //@ ensures n > 0 ==> 1 <= \result && \result <= n;
    //@ ensures n >= 0 ==> (\exists int m; 0 < m && m <= n; (\forall int i; 0 - 1 <= i && i < n; arr[m] < arr[i]));  
    //@ ensures n > 0 ==> (\exists int m; 0 <= m && m < n; (\forall int i; 0 <= i && i < n; arr[m] <= arr[i]) && \result == (\num_of int j; 0 <= j && j < n; arr[j] == arr[m]));
    public static int frequencyOfSmallest(int n, int[] arr) {
        if (n == 0) {
            return 0;
        }

        int min = arr[0];
        int count = 1;

        //@ maintaining 1 <= i && i <= n;
        //@ maintaining 1 <= count && count <= i;
        //@ maintaining (\forall int j; 0 <= j && j < i; min <= arr[j]);
 
        //@ decreases n - i;
        for (int i = 1; i < n; i++) {
            if (min > arr[i]) {
                min = arr[i];
                count = 1;
            } else if (min == arr[i]) {
                count++;
            }
        }
        return count;
    }
}