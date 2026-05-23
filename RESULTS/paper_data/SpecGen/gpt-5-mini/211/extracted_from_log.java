import java.io.*;
import java.lang.*;
import java.math.*;

class FindMinSwaps {

    /*@
      requires arr != null;
      requires 0 <= n && n <= arr.length;
      ensures 0 <= \result && \result <= n;
      ensures (\forall int idx; 0 <= idx && idx < arr.length; arr[idx] == \old(arr[idx]));
    @*/
    public static int findMinSwaps(int[] arr, int n) {
        int count = 0;
        int i = 0;
        int j = 1;

        /*@
          maintaining 0 <= i && i <= n;
          maintaining 0 <= j && j <= n;
          maintaining 0 <= count && count <= n;
          maintaining (\forall int idx; 0 <= idx && idx < arr.length; arr[idx] == \old(arr[idx]));
          decreases (n - i) + (n - j);
        @*/
        while (i < n && j < n) {
            if (arr[i] == arr[j]) {
                i++;
                j++;
                count++;
            } else if (arr[i] > arr[j]) {
                i++;
            } else {
                j++;
            }
        }

        return count;
    }
}