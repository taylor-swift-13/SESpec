import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindRotationCount {

    /*@ 
      @ requires a != null && a.length > 0;
      @ // array is a rotation of a non-decreasing (sorted) sequence
      @ requires (\exists int rot; 0 <= rot && rot < a.length &&
      @              (\forall int i; 0 <= i && i < a.length-1;
      @                  a[(rot + i) % a.length] <= a[(rot + i + 1) % a.length]));
      @ 
      @ ensures 0 <= \result && \result < a.length;
      @ // result is the index of a minimum element
      @ ensures (\forall int i; 0 <= i && i < a.length; a[\result] <= a[i]);
      @ // if result > 0 then previous element is greater (pivot)
      @ ensures (\result > 0 ==> a[\result-1] > a[\result]);
      @*/
    public static int findRotationCount(int[] a) {
        int start = 0;
        int end = a.length - 1;
        /*@ 
 
 
          @ // while the loop is active (start <= end) the global minimum index m is within [start,end]
 
          @   (\exists int m; 0 <= m && m < a.length &&
          @       (\forall int i; 0 <= i && i < a.length; a[m] <= a[i]) &&
          @       start <= m && m <= end);
          @ decreases end - start + 1;
          @*/
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (mid < end && a[mid] > a[mid + 1]) {
                return mid + 1;
            } else if (mid > start && a[mid] < a[mid - 1]) {
                return mid;
            }
            if (a[mid] >= a[start]) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return 0;
    }
}