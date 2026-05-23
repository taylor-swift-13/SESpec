import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class Search {

    /*@ 
      @ requires arr != null;
      @ requires 1 <= n && n <= arr.length;
      @ 
      @ // result is one of the elements of arr within the first n entries
      @ ensures (\exists int k; 0 <= k && k < n; \result == arr[k]);
      @ 
      @ // method does not modify the contents of arr
      @ ensures (\forall int k; 0 <= k && k < n; arr[k] == \old(arr[k]));
      @*/
    public static int search(int[] arr, int n) {
        int i = 0;
        /*@
          @ // loop index stays in bounds
          @ maintaining 0 <= i && i <= n;
          @ 
          @ // for every even index e that is fully processed (e+1 < i),
          @ // the pair arr[e], arr[e+1] was equal
 
          @ 
          @ decreases n - i;
          @*/
        while (i < n - 1) {
            if (arr[i] == arr[i + 1]) {
                i += 2;
            } else {
                return arr[i];
            }
        }
        return arr[n - 1];
    }
}