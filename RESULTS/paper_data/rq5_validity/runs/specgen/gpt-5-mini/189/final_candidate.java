import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FrequencyOfSmallest {

    /*@ 
      @ requires arr != null;
      @ requires 0 <= n && n <= arr.length;
 
      @ ensures n == 0 ==> \result == 0;
 
      @   (\exists int m; 0 <= m && m < n &&
      @       (\forall int k; 0 <= k && k < n; arr[m] <= arr[k])
      @       && \result == (\sum int i; 0 <= i && i < n; arr[i] == arr[m] ? 1 : 0)
      @   );
      @*/
    public static int frequencyOfSmallest(int n, int[] arr) {
        if (n == 0) {
            return 0;
        }

        int min = arr[0];
        int count = 1;

        /*@
          @ // Loop invariant: i ranges and min/count describe the prefix [0..i-1]
          @ maintaining 1 <= i && i <= n;
          @ maintaining (\forall int k; 0 <= k && k < i; min <= arr[k]);
          @ maintaining (\exists int j; 0 <= j && j < i; arr[j] == min);
 
          @ decreases n - i;
          @*/
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
