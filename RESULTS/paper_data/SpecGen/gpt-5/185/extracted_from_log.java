import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindFirstOccurrence {

    /*@
      @ requires a != null;
      @ requires (\forall int i; 0 <= i && i + 1 < a.length; a[i] <= a[i+1]);
      @ assignable \nothing;
      @ ensures -1 <= \result && \result < a.length;
      @ ensures \result == -1 || (a[\result] == x && (\result == 0 || a[\result - 1] != x));
      @*/
    public static int findFirstOccurrence(int[] a, int x) {
        int low = 0, high = a.length - 1;
        //@ maintaining 0 <= low && low <= a.length;
        //@ maintaining -1 <= high && high < a.length;
        //@ maintaining low <= high + 1;
        //@ decreases high - low + 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (a[mid] == x) {
                if (mid == 0 || a[mid - 1] != x) {
                    return mid;
                } else {
                    high = mid - 1;
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