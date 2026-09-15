import java.io.*;
import java.lang.*;
import java.math.*;

class FindMinSwaps {

    //@ requires arr != null;
    //@ requires 0 <= n && n <= arr.length;
    //@ assignable \nothing;
    //@ ensures 0 <= \result && \result <= n;
    //@ ensures n <= 1 ==> \result == 0;
    //@ ensures (\forall int k; 0 <= k && k < arr.length; arr[k] == \old(arr[k]));
    public static int findMinSwaps(int[] arr, int n) {
        int count = 0;
        int i = 0;
        int j = 1;

        //@ maintaining 0 <= i && i <= j && j <= n;
        //@ maintaining 0 <= count && count <= i && count <= j;
        //@ maintaining arr != null && 0 <= n && n <= arr.length;
        //@ decreases (n - i) + (n - j);
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