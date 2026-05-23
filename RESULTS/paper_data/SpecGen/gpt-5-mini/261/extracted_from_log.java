import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class RightInsertion {

    /*@ 
      @ requires a != null;
      @ requires (\forall int p, q; 0 <= p && p < q && q < a.length; a[p] <= a[q]);
      @ 
      @ ensures 0 <= \result && \result <= a.length;
      @ 
      @ // If the array contains x, the result is some index of an occurrence of x.
      @ ensures (\exists int k; 0 <= k && k < a.length; a[k] == x && \result == k)
      @ 
      @ // Otherwise, result is the insertion position: all elements before it are < x
      @ // and all elements from it (if any) are > x.
      @    || ((\forall int k; 0 <= k && k < a.length; a[k] != x)
      @        && (\forall int k; 0 <= k && k < \result; a[k] < x)
      @        && (\forall int k; \result <= k && k < a.length; a[k] > x));
      @*/
    public static int rightInsertion(int[] a, int x) {
        int i = 0;
        int j = a.length - 1;
        /*@ 
          @ maintaining 0 <= i && i <= a.length;
          @ maintaining -1 <= j && j < a.length;
          @ maintaining (\forall int k; 0 <= k && k < i; a[k] < x);
          @ maintaining (\forall int k; j < k && k < a.length; a[k] > x);
          @ maintaining (\forall int p, q; 0 <= p && p < q && q < a.length; a[p] <= a[q]);
          @ decreases j - i + 1;
          @*/
        while (i <= j) {
            int mid = (i + j) / 2;
            if (a[mid] == x) {
                return mid;
            } else if (a[mid] < x) {
                i = mid + 1;
            } else {
                j = mid - 1;
            }
        }
        return i;
    }
}