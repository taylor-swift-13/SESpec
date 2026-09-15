import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class GetPairsCount {

    /*@ 
      @ requires arr != null;
      @ requires 0 <= n && n <= arr.length;
      @ ensures 0 <= \result && \result <= n*(n-1)/2;
      @ ensures \result == (\num_of int p,q; 0 <= p && p < q && q < n && arr[p] + arr[q] == sum; 1);
      @*/
    public static int getPairsCount(int[] arr, int n, int sum) {
        int count = 0;
        /*@ 
          @ maintaining 0 <= i && i <= n;
          @ maintaining count == (\num_of int p,q; 0 <= p && p < q && q < n && p < i && arr[p] + arr[q] == sum; 1);
          @ decreases n - i;
          @*/
        for (int i = 0; i < n; i++) {
            /*@ 
              @ maintaining i + 1 <= j && j <= n;
              @ maintaining count == 
              @    (\num_of int p,q; 0 <= p && p < q && q < n && p < i && arr[p] + arr[q] == sum; 1)
              @  + (\num_of int q; i < q && q < j && arr[i] + arr[q] == sum; 1);
              @ decreases n - j;
              @*/
            for (int j = i + 1; j < n; j++) {
                if (arr[i] + arr[j] == sum) {
                    count++;
                }
            }
        }
        return count;
    }
}