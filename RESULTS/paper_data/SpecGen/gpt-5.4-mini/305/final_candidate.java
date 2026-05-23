import java.io.*;
import java.lang.*;
import java.math.*;

class FindPeak {

    //@ requires arr != null;
    //@ requires 0 < n && n <= arr.length;
    //@ ensures 0 <= \result && \result < n;
 
 
    public static int findPeak(int[] arr, int n) {
        int left = 0, right = n - 1;
        //@ maintaining 0 <= left && left <= right && right < n;
        //@ decreases right - left;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] < arr[mid + 1]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
}
