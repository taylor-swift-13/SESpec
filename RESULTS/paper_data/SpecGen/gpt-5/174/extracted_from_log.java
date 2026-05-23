import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindRotationCount {

    //@ requires a != null;
    //@ assignable \nothing;
    //@ ensures a.length == 0 ==> \result == 0;
    //@ ensures a.length > 0 ==> 0 <= \result && \result < a.length;
    public static int findRotationCount(int[] a) {
        int start = 0;
        int end = a.length - 1;
        //@ maintaining 0 <= start && start <= a.length;
        //@ maintaining -1 <= end && end < a.length;
        //@ maintaining start <= end + 1;
        //@ decreases end - start + 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            //@ assert start <= mid && mid <= end;
            //@ assert 0 <= mid && mid < a.length;
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