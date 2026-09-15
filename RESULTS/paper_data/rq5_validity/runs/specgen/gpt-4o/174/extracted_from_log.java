import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindRotationCount {

    //@ requires a.length > 0;
    //@ requires (\forall int i; 0 <= i && i < a.length - 1; a[i] <= a[i + 1] || a[a.length - 1] <= a[0]);
    //@ ensures \result >= 0 && \result < a.length;
    //@ ensures (\result == 0 || a[\result - 1] > a[\result]);
    public static int findRotationCount(int[] a) {
        int start = 0;
        int end = a.length - 1;

        //@ maintaining 0 <= start && start - 1 <= end && end < a.length;  
        //@ decreases end - start;
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