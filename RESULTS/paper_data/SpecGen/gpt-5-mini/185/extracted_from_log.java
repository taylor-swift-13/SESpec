import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindFirstOccurrence {

    /*@ 
      @ requires a != null;
      @ 
      @ // If a non-negative index is returned it is an index of x
      @ ensures (\result == -1) || (0 <= \result && \result < a.length && a[\result] == x);
      @ 
      @ // If a non-negative index is returned, its immediate predecessor (if any) is not x
      @ ensures (\result >= 0) ==> (\result == 0 || a[\result - 1] != x);
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