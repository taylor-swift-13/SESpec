import java.io.*;
import java.lang.*;
import java.math.*;

class GetOddOccurrence {

    /*@ 
      @ requires arr != null;
      @ requires 0 <= arrSize && arrSize <= arr.length;
      @ 
      @ // If there are no odd elements in the considered prefix, result is 0
      @ ensures (\sum int i; 0 <= i && i < arrSize; (arr[i] % 2 != 0 ? 1 : 0)) == 0 ==> \result == 0;
      @ 
      @ // If the number of odd elements in the prefix is odd, result equals the last odd element
 
      @          ==> (\exists int last; 0 <= last && last < arrSize && (arr[last] % 2 != 0) 
      @                  && (\forall int j; last < j && j < arrSize; (arr[j] % 2 == 0))
      @                  && \result == arr[last]);
      @ 
      @ // If the number of odd elements in the prefix is even and > 0, result equals the
      @ // penultimate odd element (the last odd before the final odd)
      @ ensures (\sum int i; 0 <= i && i < arrSize; (arr[i] % 2 != 0 ? 1 : 0)) % 2 == 0
      @          && (\sum int i; 0 <= i && i < arrSize; (arr[i] % 2 != 0 ? 1 : 0)) > 0
      @          ==> (\exists int last, prev;
      @                  0 <= prev && prev < last && last < arrSize
      @                  && (arr[last] % 2 != 0) && (arr[prev] % 2 != 0)
      @                  && (\forall int j; last < j && j < arrSize; (arr[j] % 2 == 0))
      @                  && (\forall int t; prev < t && t < last; (arr[t] % 2 == 0))
      @                  && \result == arr[prev]);
      @*/
    public static int getOddOccurrence(int[] arr, int arrSize) {
        int result = 0;
        int count = 0;
        /*@ 
          @ maintaining 0 <= i && i <= arrSize;
 
          @ maintaining (count == 0) ==> result == 0;
          @ // If there have been odd elements, result is equal to some seen odd element
          @ // whose occurrence-number among odds so far is odd.
          @ maintaining (count > 0) 
          @            ==> (\exists int p; 0 <= p && p < i && (arr[p] % 2 != 0)
          @                          && (\sum int k; 0 <= k && k <= p; (arr[k] % 2 != 0 ? 1 : 0)) % 2 == 1
          @                          && result == arr[p]);
          @*/
        for (int i = 0; i < arrSize; i++) {
            if (arr[i] % 2 != 0) {
                count++;
                if (count % 2 != 0) {
                    result = arr[i];
                }
            }
        }
        return result;
    }
}