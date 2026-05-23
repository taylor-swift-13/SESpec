import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class GetPairsCount {

    /*@ 
      @ requires arr != null;
      @ requires 0 <= n && n <= arr.length;
      @ assignable \nothing;
      @ ensures \result == (\sum int p; 0 <= p && p < n; 
      @                        (\sum int q; p+1 <= q && q < n; 
      @                           (arr[p] + arr[q] == sum ? 1 : 0)));
      @ ensures 0 <= \result && \result <= (n * (n - 1)) / 2;
      @*/
    public static int getPairsCount(int[] arr, int n, int sum) {
        int count = 0;
        //@ maintaining 0 <= i && i <= n;
        //@ maintaining 0 <= count && count <= (n * (n - 1)) / 2;
        //@ maintaining count == (\sum int p; 0 <= p && p < i; 
        //@                          (\sum int q; p+1 <= q && q < n; 
        //@                             (arr[p] + arr[q] == sum ? 1 : 0)));
        //@ decreases n - i;
        for (int i = 0; i < n; i++) {
            //@ maintaining i >= 0 && i < n;
            //@ maintaining i+1 <= j && j <= n;
            //@ maintaining 0 <= count && count <= (n * (n - 1)) / 2;
            //@ maintaining count == (\sum int p; 0 <= p && p < i; 
            //@                          (\sum int q; p+1 <= q && q < n; 
            //@                             (arr[p] + arr[q] == sum ? 1 : 0)))
            //@                    + (\sum int q; i+1 <= q && q < j; 
            //@                          (arr[i] + arr[q] == sum ? 1 : 0));
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