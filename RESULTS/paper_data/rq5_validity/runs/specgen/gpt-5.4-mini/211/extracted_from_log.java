import java.io.*;
import java.lang.*;
import java.math.*;

class FindMinSwaps {

    //@ requires arr != null;
    //@ requires 0 <= n && n <= arr.length;
    //@ ensures \result >= 0;
    //@ ensures \result <= n;
    public static int findMinSwaps(int[] arr, int n) {
        int count = 0;
        int i = 0;
        int j = 1;

        //@ maintaining 0 <= i && i <= n;
        //@ maintaining 1 <= j && j - 1 <= n;  
        //@ maintaining 0 <= count && count <= i;
 
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