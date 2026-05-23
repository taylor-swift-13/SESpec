import java.io.*;
import java.lang.*;
import java.math.*;

class FindPeak {

    /*@
      @ requires arr != null;
      @ requires n > 0;
      @ requires n <= arr.length;
      @ 
      @ // Result is a valid index in the prefix of length n
      @ ensures 0 <= \result && \result < n;
      @ 
      @ // Result is a local peak (compares with neighbors when they exist)
 
 
      @*/
    public static int findPeak(int[] arr, int n) {
        int left = 0, right = n - 1;
        /*@
          @ maintaining 0 <= left && left <= right && right < n;
          @ 
          @ // mid computed in the loop body is between left (inclusive) and right (exclusive)
          @ maintaining left < right ==> left <= left + (right - left) / 2 && left + (right - left) / 2 < right;
          @ 
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
