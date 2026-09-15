import java.io.*;
import java.lang.*;
import java.math.*;

class FindPeak {

    /*@ requires arr != null;
      @ requires 1 <= n && n <= arr.length;
      @ assignable \nothing;
      @ ensures 0 <= \result && \result < n;
      @*/
    public static int findPeak(int[] arr, int n) {
        int left = 0, right = n - 1;
        /*@
          @ maintaining 0 <= left && left <= right && right < n;
          @ maintaining left < right ==> left + (right - left) / 2 + 1 <= right;
          @ decreases right - left;
          @*/
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