import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindExtra {

    /*@ requires arr1 != null;
      @ requires arr2 != null;
      @ requires n == arr1.length;
      @ requires n == arr2.length + 1;
      @ requires (\forall int k; 0 <= k && k < arr2.length - 1; arr2[k] <= arr2[k+1]);
      @ requires (\forall int k; 0 <= k && k < arr1.length - 1; arr1[k] <= arr1[k+1]);
      @ ensures 0 <= \result && \result < n;
      @*/
    public static int findExtra(int[] arr1, int[] arr2, int n) {
        int i = 0;
        int j = 0;
        /*@ maintaining 0 <= i && i <= arr1.length;
          @ maintaining 0 <= j && j <= arr2.length;
          @ decreases (arr1.length - i) + (arr2.length - j);
          @*/
        while (i < arr1.length && j < arr2.length) {
            if (arr1[i] < arr2[j]) {
                i++;
            } else if (arr1[i] > arr2[j]) {
                j++;
            } else {
                i++;
                j++;
            }
        }
        return i < arr1.length ? i : j;
    }
}