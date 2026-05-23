import java.io.*;
import java.lang.*;
import java.math.*;

class FindMinSwaps {

    //@ requires arr != null && arr.length == n && n > 0;
    //@ ensures \result >= 0;
    //@ ensures (\forall int i, j; 0 < i && i < j && j < n; arr[i] == arr[j] ==> \result + 1 >= 1);  
    public static int findMinSwaps(int[] arr, int n) {
        int count = 0;
        int i = 0;
        int j = 1;

        //@ maintaining 0 <= i && i <= n && 1 <= j && j <= n;  
        //@ maintaining count >= 0;
        //@ maintaining (\forall int k, l; 0 < k && k < l && l < i; arr[k] == arr[l] ==> count + 1 >= 1);  
 
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