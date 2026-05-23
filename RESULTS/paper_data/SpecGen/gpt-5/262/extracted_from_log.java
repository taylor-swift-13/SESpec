import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

/*@ spec_public @*/
class LeftInsertion {

    /*@
      @ requires a != null;
      @ requires (\forall int k; 0 <= k && k + 1 < a.length; a[k] <= a[k+1]);
      @ ensures 0 <= \result && \result <= a.length;
      @ ensures (\forall int i; 0 <= i && i < \result; a[i] <= x);
      @ ensures (\forall int i; \result <= i && i < a.length; x <= a[i]);
      @*/
    public static int leftInsertion(int[] a, int x) {
        int left = 0;
        int right = a.length - 1;
        /*@
          @ maintaining 0 <= left && left <= a.length;
          @ maintaining -1 <= right && right < a.length;
          @ maintaining (\forall int i; 0 <= i && i < left; a[i] <= x);
          @ maintaining (\forall int i; right < i && i < a.length; x <= a[i]);
          @ maintaining (\forall int k; 0 <= k && k + 1 < a.length; a[k] <= a[k+1]);
          @ decreases right - left + 1;
          @*/
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