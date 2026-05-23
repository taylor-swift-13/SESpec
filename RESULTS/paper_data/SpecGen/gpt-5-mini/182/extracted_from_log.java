import java.io.*;
import java.lang.*;
import java.util.*;

class FindLastOccurrence {

    /*@ spec_public
      @ public normal_behavior
      @   requires a != null;
      @   // array must be sorted in non-decreasing order for the binary search to be valid
      @   requires (\forall int i; 0 <= i && i+1 < a.length; a[i] <= a[i+1]);
      @   // If result is -1 then x does not occur in the array, otherwise result is the last index where x occurs
      @   ensures (\result == -1) <==> (\forall int i; 0 <= i && i < a.length; a[i] != x);
      @   ensures 0 <= \result && \result < a.length ==>
      @           (a[\result] == x && (\forall int j; \result < j && j < a.length; a[j] != x));
      @   assignable \nothing;
      @*/
    public static int findLastOccurrence(int[] a, int x) {
        int low = 0;
        int high = a.length - 1;
        int mid = 0;
        /*@ maintaining 0 <= low && low <= a.length;
          @ maintaining -1 <= high && high < a.length;
          @ maintaining low <= high + 1;
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