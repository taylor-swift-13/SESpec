import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class CountRotation {

    /*@ 
      @ requires arr != null;
      @ requires 0 <= n && n <= arr.length;
      @ ensures (n == 0 ==> \result == 0);
      @ ensures (n > 0 ==> 1 <= \result && \result <= n);
      @ ensures (\forall int i; 0 <= i && i < arr.length; arr[i] == \old(arr[i]));
      @*/
    public /*@ spec_public @*/ static int countRotation(int[] arr, int n) {
        if (n == 0) {
            return 0;
        }
        int left = 0, right = n - 1;
        //@ maintaining 0 <= left && left <= right && right < n;
        //@ maintaining (\forall int i; 0 <= i && i < arr.length; arr[i] == \old(arr[i]));
        //@ decreases right - left;
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