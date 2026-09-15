import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class Last {

    /*@ requires arr != null;
      @ requires 0 <= n && n <= arr.length;
      @ requires (\forall int k; 0 <= k && k + 1 < n; arr[k] <= arr[k+1]);
      @ assignable \nothing;
      @ ensures -1 <= \result && \result < n;
      @ ensures \result == -1 || arr[\result] == x;
      @ ensures \result == -1 || \result == n - 1 || arr[\result + 1] > x;
      @*/
    public static int last(int[] arr, int x, int n) {
        int i = 0;
        int j = n - 1;
        int result = -1;

        /*@ maintaining 0 <= i && i <= n;
          @ maintaining -1 <= j && j < n;
          @ maintaining i <= j + 1;
          @ maintaining result == -1 || (0 <= result && result < n && arr[result] == x && result < i);
          @ decreases j - i + 1;
          @*/
        while (i <= j) {
            int mid = (i + j) / 2;
            if (arr[mid] == x) {
                result = mid;
                i = mid + 1;
            } else if (arr[mid] < x) {
                i = mid + 1;
            } else {
                j = mid - 1;
            }
        }

        return result;
    }
}