import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindKth {

    //@ requires arr1 != null && arr != null;
    //@ requires arr1.length == len1 && arr.length == len2;
    //@ requires len1 >= 0 && len2 >= 0 && k > 0 && k <= len1 + len2;
    //@ requires \forall int i; 0 <= i && i < len1 - 1; arr1[i] <= arr1[i + 1];
    //@ requires \forall int i; 0 <= i && i < len2 - 1; arr[i] <= arr[i + 1];
 
    public static int findKth(int[] arr1, int[] arr, int len1, int len2, int k) {
        int index1 = 0;
        int index2 = 0;
        int result = 0;

        //@ maintaining 0 <= index1 && index1 <= len1;
        //@ maintaining 0 <= index2 && index2 <= len2;
        //@ maintaining 0 <= count && count <= k;
        //@ decreases k - count;
        for (int count = 0; count < k; count++) {
            if (index1 < len1 && (index2 >= len2 || arr1[index1] <= arr[index2])) {
                result = arr1[index1];
                index1++;
            } else {
                result = arr[index2];
                index2++;
            }
        }
        return result;
    }
}