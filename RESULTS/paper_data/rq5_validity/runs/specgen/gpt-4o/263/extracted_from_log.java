import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindFixedPoint {

    //@ requires arr != null && arr.length == n;
 
    //@ ensures 0 <= \result && \result < n ==> arr[\result] == \result;
    public static int findFixedPoint(int[] arr, int n) {
        int start = 0;
        int end = n - 1;
        //@ maintaining 0 <= start && start <= end + 1 && end < n;
 
 
        //@ decreases end - start + 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (arr[mid] == mid) {
                return mid;
            } else if (arr[mid] < mid) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return -1;
    }
}