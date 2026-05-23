import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FrequencyOfSmallest {

    //@ requires n >= 0 && arr != null && arr.length >= n;
    //@ ensures n == 0 ==> \result == 0;
    //@ ensures n > 0 ==> (\exists int minIndex; 0 <= minIndex && minIndex < n; (\forall int i; 0 <= i && i < n; arr[minIndex] <= arr[i]) && \result == (\sum int j; 0 <= j && j < n; arr[j] == arr[minIndex] ? 1 : 0));
    public static int frequencyOfSmallest(int n, int[] arr) {
        if (n == 0) {
            return 0;
        }

        int min = arr[0];
        int count = 1;

        //@ maintaining 1 <= i && i <= n;
        //@ maintaining (\exists int minIndex; 0 <= minIndex && minIndex < i; (\forall int j; 0 <= j && j < i; arr[minIndex] <= arr[j]) && min == arr[minIndex]);
 
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