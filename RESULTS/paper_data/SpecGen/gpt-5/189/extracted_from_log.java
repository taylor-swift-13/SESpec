import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FrequencyOfSmallest {

    //@ requires arr != null && 0 <= n && n <= arr.length;
    //@ ensures n == 0 ==> \result == 0;
    //@ ensures n > 0 ==> (\exists int m; (\forall int k; 0 <= k && k < n; m <= arr[k]) && (\exists int idx; 0 <= idx && idx < n; arr[idx] == m) && \result == (\num_of int i; 0 <= i && i < n; arr[i] == m));
    //@ ensures 0 <= \result && \result <= n;
    public static int frequencyOfSmallest(int n, int[] arr) {
        if (n == 0) {
            return 0;
        }

        int min = arr[0];
        int count = 1;

        //@ maintaining n > 0 ==> (1 <= i && i <= n);
        //@ maintaining n > 0 ==> (\forall int k; 0 <= k && k < i; min <= arr[k]);
        //@ maintaining n > 0 ==> (\exists int t; 0 <= t && t < i; arr[t] == min);
        //@ maintaining n > 0 ==> (count == (\num_of int k; 0 <= k && k < i; arr[k] == min));
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