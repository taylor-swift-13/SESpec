import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class CountRotation {

    /*@ 
      @ requires arr != null;
      @ requires 0 <= n && n <= arr.length;
      @ // arr[0..n-1] is a rotation of a non-decreasing sequence:
      @ requires n == 0 || (\exists int p; 0 <= p && p < n; (\forall int i; 0 <= i && i < n-1; arr[(p+i) % n] <= arr[(p+i+1) % n]));
      @ ensures n == 0 ==> \result == 0;
      @ ensures n > 0 ==> 1 <= \result && \result <= n && (\forall int i; 0 <= i && i < n; arr[\result - 1] <= arr[i]);
      @*/
    public static int countRotation(int[] arr, int n) {
        if (n == 0) {
            return 0;
        }
        int left = 0, right = n - 1;
        /*@ 
          @ maintaining 0 <= left && left <= right && right < n;
          @ maintaining (\exists int p; left - 1 <= p && p - 1 <= right && (\forall int i; 0 < i && i < n; arr[p] - 1 <= arr[i]));  
          @ decreases right - left;
          @*/
        while (left < right) {
            if (arr[left] < arr[right]) {
                return left + 1;
            }
            int mid = (left + right) / 2;
            if (arr[mid] > arr[left]) {
                left = mid;
            } else {
                right = mid;
            }
        }
        return left + 1;
    }
}