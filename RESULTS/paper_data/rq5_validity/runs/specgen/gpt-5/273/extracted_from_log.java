import java.io.*;
import java.lang.*;
import java.math.*;

class SumOfSubarrayProd {

    /*@ requires arr != null && 0 <= n && n <= arr.length;
      @ assignable \nothing;
      @ ensures \result ==
      @   ( \sum int i; 0 <= i && i < n;
      @       ( \sum int j; i <= j && j < n;
      @           ( \product int k; i <= k && k <= j; arr[k] )
      @       )
      @   );
      @*/
    public static int sumOfSubarrayProd(int[] arr, int n) {
        int sum = 0;
        //@ maintaining arr != null && 0 <= n && n <= arr.length;
        //@ maintaining 0 <= i && i <= n;
        //@ maintaining sum == ( \sum int p; 0 <= p && p < i;
        //@                        ( \sum int q; p <= q && q < n;
        //@                            ( \product int k; p <= k && k <= q; arr[k] ) ) );
        //@ decreases n - i;
        for (int i = 0; i < n; i++) {
            int product = 1;
            //@ maintaining arr != null && 0 <= n && n <= arr.length;
            //@ maintaining i <= j && j <= n;
            //@ maintaining product == ( \product int k; i <= k && k < j; arr[k] );
            //@ maintaining sum == ( \sum int p; 0 <= p && p < i;
            //@                        ( \sum int q; p <= q && q < n;
            //@                            ( \product int k; p <= k && k <= q; arr[k] ) ) )
            //@                   + ( \sum int q; i <= q && q < j;
            //@                        ( \product int k; i <= k && k <= q; arr[k] ) );
            //@ decreases n - j;
            for (int j = i; j < n; j++) {
                product *= arr[j];
                sum += product;
            }
        }
        return sum;
    }
}