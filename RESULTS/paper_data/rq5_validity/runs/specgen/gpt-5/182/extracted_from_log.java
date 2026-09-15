import java.io.*;
import java.lang.*;
import java.util.*;

class FindLastOccurrence {

    /*@ spec_public @*/
    /*@
      @ requires a != null;
      @ requires (\forall int i; 0 <= i && i + 1 < a.length; a[i] <= a[i + 1]);
      @ assignable \nothing;
      @ ensures \result == -1 
      @      || (0 <= \result && \result < a.length
      @          && a[\result] == x
      @          && (\result == a.length - 1 || a[\result + 1] != x));
      @*/
    public static int findLastOccurrence(int[] a, int x) {
        int low = 0;
        int high = a.length - 1;
        int mid = 0;
        /*@
          @ maintaining 0 <= low && -1 <= high && high < a.length && low <= high + 1;
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