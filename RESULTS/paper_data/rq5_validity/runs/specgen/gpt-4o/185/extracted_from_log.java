import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindFirstOccurrence {

    //@ requires a != null;
    //@ requires a.length > 0;
    //@ requires (\forall int i; 0 <= i && i < a.length - 1; a[i] <= a[i + 1]); // Array must be sorted
    //@ ensures \result == -1 || (0 <= \result && \result < a.length && a[\result] == x); // Result is valid or -1
    //@ ensures \result != -1 ==> (\result == 0 || a[\result - 1] != x); // First occurrence condition
    public static int findFirstOccurrence(int[] a, int x) {
        int low = 0, high = a.length - 1;

        //@ maintaining 0 <= low && low <= high + 1 && high < a.length;
        //@ maintaining (\forall int i; 0 <= i && i < low; a[i] < x); // Elements before low are less than x
        //@ maintaining (\forall int i; high + 1 <= i && i < a.length; a[i] > x); // Elements after high are greater than x
        //@ decreases high - low + 1; // Loop decreases range
        while (low <= high) {
            int mid = low + (high - low) / 2;
            //@ assert 0 <= mid && mid < a.length;

            if (a[mid] == x) {
                if (mid == 0 || a[mid - 1] != x) {
                    return mid; // Found the first occurrence
                } else {
                    high = mid - 1; // Search in the left half
                }
            } else if (a[mid] < x) {
                low = mid + 1; // Search in the right half
            } else {
                high = mid - 1; // Search in the left half
            }
        }
        return -1; // Element not found
    }
}