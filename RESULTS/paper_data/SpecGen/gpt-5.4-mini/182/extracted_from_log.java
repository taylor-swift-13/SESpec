import java.io.*;
import java.lang.*;
import java.util.*;

class FindLastOccurrence {

    /*@ requires a != null;
 
      @      || (\result >= 0 && \result < a.length && a[\result] == x
      @          && (\result == a.length - 1 || a[\result + 1] != x));
      @*/
    public static int findLastOccurrence(int[] a, int x) {
        int low = 0;
        int high = a.length - 1;
        int mid = 0;
        /*@ maintaining 0 <= low && low <= a.length;
          @ maintaining -1 <= high && high < a.length;
          @ maintaining low <= high + 1;
          @ maintaining (\forall int i; 0 < i && i < low; a[i] <= x);  
          @ maintaining (\forall int i; high < i && i < a.length; a[i] > x);
          @ decreases high - low + 1;
          @*/
        while (low <= high) {
            mid = (low + high) / 2;
            if (a[mid] == x) {
                if (mid == a.length - 1 || a[mid + 1] != x) {
                    return mid;
                } else {
                    low = mid + 1;
                }
            } else if (a[mid] < x) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return -1;
    }
}