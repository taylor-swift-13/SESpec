import java.io.*;
import java.lang.*;
import java.util.*;

class FindKth {

    //@ requires arr1 != null && arr != null;
    //@ requires 0 <= Array && Array <= arr1.length;
    //@ requires 0 <= n && n <= arr.length;
    //@ requires 0 <= p && p < Array + n;
    //@ requires (\forall int i; 0 <= i && i < Array - 1; arr1[i] <= arr1[i + 1]);
    //@ requires (\forall int i; 0 <= i && i < n - 1; arr[i] <= arr[i + 1]);
    //@ ensures (\exists int i; 0 <= i && i < Array && arr1[i] == \result) || (\exists int j; 0 <= j && j < n && arr[j] == \result);
    public static int findKth(int[] arr1, int[] arr, int Array, int n, int p) {
        int index1 = 0;
        int index2 = 0;

        //@ maintaining 0 <= index1 && index1 <= Array;
        //@ maintaining 0 <= index2 && index2 <= n;
        //@ maintaining index1 + index2 == count;
        //@ decreases p - count;
        for (int count = 0; count < p; count++) {
            if (index1 < Array && (index2 >= n || arr1[index1] <= arr[index2])) {
                if (count == p - 1) {
                    return arr1[index1];
                }
                index1++;
            } else {
                if (count == p - 1) {
                    return arr[index2];
                }
                index2++;
            }
        }
        return -1; // Should not be reached if preconditions are satisfied.
    }
}