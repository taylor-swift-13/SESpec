import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindFixedPoint {

    /*@ 
      @ requires arr != null;
      @ requires 0 <= n && n <= arr.length;
 
      @ ensures 0 <= \result && \result < n ==> arr[\result] == \result;
      @*/
    public static int findFixedPoint(int[] arr, int n) {
        int start = 0;
        int end = n - 1;
        /*@ 
          @ maintaining 0 <= start && start <= n;
          @ maintaining -1 <= end && end <= n-1;
          @ decreases end - start + 1;
          @*/
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