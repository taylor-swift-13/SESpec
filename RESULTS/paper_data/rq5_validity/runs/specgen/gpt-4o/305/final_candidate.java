import java.io.*;
import java.lang.*;
import java.math.*;

class FindPeak {

    //@ requires arr != null && arr.length == n && n > 0;
    //@ ensures 0 <= \result && \result < n;
    //@ ensures (\result == 0 || arr[\result] >= arr[\result - 1]) && (\result == n - 1 || arr[\result] >= arr[\result + 1]);
    public static int findPeak(int[] arr, int n) {
        int left = 0, right = n - 1;
        //@ maintaining 0 <= left && left <= right && right < n;
        //@ maintaining (\exists int i; left < i && i < right; (i == 0 && arr[i] > arr[i - 1]) || (i == n - 1 && arr[i] > arr[i + 1]));  
        //@ decreases right - left;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] < arr[mid + 1]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        //@ assert (\forall int i; 0 <= i && i < n; (i == 0 || arr[i] >= arr[i - 1]) && (i == n - 1 || arr[i] >= arr[i + 1]) ==> (i == left));
        return left;
    }
}
