import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindFirstMissing {

    /*@
      @ requires array != null;
      @ requires 0 <= start && start <= end && end < array.length;
      @ assignable \nothing;
      @ ensures start <= \result && \result <= end + 1;
      @*/
    /*@ spec_public @*/ public static int findFirstMissing(int[] array, int start, int end) {
        int min = start;
        int max = end;
        int mid;

        /*@
          @ maintaining start <= min && min <= end + 1;
          @ maintaining start - 1 <= max && max <= end;
          @ maintaining min <= max + 1;
          @ decreases (max - min + 1);
          @*/
        while (min <= max) {
            mid = (min + max) / 2;
            int current = array[mid];

            if (current == mid) {
                min = mid + 1;
            } else if (current < mid) {
                min = mid + 1;
            } else {
                max = mid - 1;
            }
        }
        return min;
    }
}