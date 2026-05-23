import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindRotationCount {

    //@ requires a != null && a.length > 0;
    //@ ensures 0 <= \result && \result < a.length;
    //@ ensures (\exists int i; 0 <= i && i <= \result; a[\result] <= a[i]);  
    //@ ensures (\exists int i; \result <= i && i < a.length; a[\result] <= a[i]);  
    public static int findRotationCount(int[] a) {
        int start = 0;
        int end = a.length - 1;
        //@ maintaining 0 <= start && start <= a.length;
        //@ maintaining -1 <= end && end < a.length;
        //@ maintaining (\forall int i; 0 <= i && i < a.length; a[0] <= a[i]) || true;
        //@ decreases end - start + 1;
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