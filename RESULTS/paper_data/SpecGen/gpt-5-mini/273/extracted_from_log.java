import java.io.*;
import java.lang.*;
import java.math.*;

class SumOfSubarrayProd {

    /*@ 
      @ requires arr != null;
      @ requires 0 <= n && n <= arr.length;
      @ ensures \result == (\sum int i; 0 <= i && i < n; 
      @                         (\sum int j; i <= j && j < n; 
      @                             (\product int k; i <= k && k <= j; arr[k])
      @                         )
      @                    );
      @*/
    public static int sumOfSubarrayProd(int[] arr, int n) {
        int sum = 0;
        /*@ 
 
 
          @                           (\sum int q; p <= q && q < n;
          @                               (\product int r; p <= r && r <= q; arr[r])
          @                           )
          @                      );
          @ decreases n - i;
          @*/
        for (int i = 0; i < n; i++) {
            int product = 1;
            /*@
              @ maintaining i <= j && j <= n;
              @ maintaining product == (\product int k; i <= k && k < j; arr[k]);
              @ maintaining sum == (\sum int p; 0 <= p && p < i;
              @                           (\sum int q; p <= q && q < n;
              @                               (\product int r; p <= r && r <= q; arr[r])
              @                           )
              @                      )
              @                      + (\sum int q; i <= q && q < j;
              @                             (\product int r; i <= r && r <= q; arr[r])
              @                        );
              @ decreases n - j;
              @*/
            for (int j = i; j < n; j++) {
                product *= arr[j];
                sum += product;
            }
        }
        return sum;
    }
}