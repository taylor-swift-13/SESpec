import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindExtra {

    /*@ requires arr1 != null && arr2 != null;
      @ ensures 0 <= \result && ((\result <= arr1.length) || (\result <= arr2.length));
      @ ensures (\forall int k; 0 <= k && k < arr1.length; arr1[k] == \old(arr1[k]));
      @ ensures (\forall int k; 0 <= k && k < arr2.length; arr2[k] == \old(arr2[k]));
      @ ensures (\forall int k; 0 <= k && k < arr1.length && k < arr2.length; arr1[k] == arr2[k])
      @          ==> \result == (arr1.length <= arr2.length ? arr1.length : arr2.length);
      @*/
    public static int findExtra(int[] arr1, int[] arr2, int n) {
        int i = 0;
        int j = 0;
        /*@ maintaining 0 <= i && i <= arr1.length;
          @ maintaining 0 <= j && j <= arr2.length;
          @ maintaining (\forall int k; 0 <= k && k < arr1.length; arr1[k] == \old(arr1[k]));
          @ maintaining (\forall int k; 0 <= k && k < arr2.length; arr2[k] == \old(arr2[k]));
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