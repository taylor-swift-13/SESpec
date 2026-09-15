import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class LeftInsertion {

    //@ requires a != null;
    //@ ensures 0 <= \result && \result <= a.length;
    public static int leftInsertion(int[] a, int x) {
        int left = 0;
        int right = a.length - 1;
        //@ maintaining 0 <= left && left <= a.length;
        //@ maintaining -1 <= right && right < a.length;
        //@ maintaining left <= right + 1;
        //@ decreases right - left + 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (a[mid] == x) {
                return mid;
            } else if (a[mid] < x) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
}