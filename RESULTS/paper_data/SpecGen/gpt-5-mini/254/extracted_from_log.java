import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindFirstMissing {

    /*@ 
      @ requires array != null;
      @ requires 0 <= start && start <= end && end < array.length;
      @ 
      @ // The specification assumes there exists an index m in [start, end+1]
      @ // such that array[i] == i for all start <= i < m and array[j] > j
      @ // for all m <= j <= end. The method is specified to return that m.
      @ requires (\exists int m; start <= m && m <= end + 1
      @            && (\forall int i; start <= i && i < m; array[i] == i)
      @            && (\forall int j; m <= j && j <= end; array[j] > j));
      @ 
 
      @ ensures (\forall int i; start <= i && i < \result; array[i] == i);
      @ ensures (\result == end + 1
      @           ? (\forall int j; start <= j && j <= end; array[j] == j)
      @           : array[\result] > \result);
      @ 
      @ // More compact characterization: the result is the m guaranteed by the precondition
      @ ensures (\exists int m; start <= m && m <= end + 1
      @            && (\forall int i; start <= i && i < m; array[i] == i)
      @            && (\forall int j; m <= j && j <= end; array[j] > j)
      @            && \result == m);
      @*/
    public static int findFirstMissing(int[] array, int start, int end) {
        int min = start;
        int max = end;
        int mid;

        /*@ 
          @ maintaining start <= min && max <= end + 0;
          @ maintaining (\forall int i; start <= i && i < min; array[i] == i);
          @ maintaining (\forall int j; max < j && j <= end; array[j] > j);
          @ decreases max - min + 1;
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