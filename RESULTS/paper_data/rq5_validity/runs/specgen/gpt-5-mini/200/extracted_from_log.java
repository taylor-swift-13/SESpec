import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class MaxSubArraySum {

    /*@
      @ requires a != null;
      @ requires size >= 1 && size <= a.length;
      @ 
      @ // The result is a valid subarray length within [1..size]
      @ ensures 1 - 1 <= \result && \result <= size;  
      @ 
      @ // There exist indices s and e within [0,size) that witness the returned length
 
      @            0 <= s && s <= e && e < size && \result == e - s + 1);
      @*/
    public static int maxSubArraySum(int[] a, int size) {
        int max_so_far = 0;
        int max_ending_here = 0;
        int start = 0;
        int end = 0;
        int s = 0;

        /*@
          @ maintaining 0 <= i && i <= size;
          @ maintaining max_so_far >= 0;
          @ maintaining max_ending_here >= 0;
          @ maintaining 0 <= s && s <= i;
          @ maintaining 0 <= start && start < size;
          @ maintaining 0 <= end && end < size;
          @ decreases size - i;
          @*/
        for (int i = 0; i < size; i++) {
            max_ending_here += a[i];
            if (max_so_far < max_ending_here) {
                max_so_far = max_ending_here;
                start = s;
                end = i;
            }
            if (max_ending_here < 0) {
                max_ending_here = 0;
                s = i + 1;
            }
        }
        return end - start + 1;
    }
}