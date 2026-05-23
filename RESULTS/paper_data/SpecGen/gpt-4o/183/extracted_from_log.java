import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class CountRotation {

    //@ requires n >= 0 && arr.length == n;
    //@ requires (\exists int i; 0 <= i && i < n; (\forall int j; 0 <= j && j < n - 1; arr[(i + j) % n] <= arr[(i + j + 1) % n]));
    //@ ensures (\forall int i; 0 <= i && i < n - 1; arr[(\result - 1 + i) % n] <= arr[(\result - 1 + i + 1) % n]);
    //@ ensures arr[(\result - 1) % n] <= arr[(\result - 2 + n) % n];
    public static int countRotation(int[] arr, int n) {
        if (n == 0) {
            return 0;
        }
        int left = 0, right = n - 1;
        //@ maintaining 0 <= left && left < n && 0 <= right && right < n && left <= right;
        //@ maintaining (\exists int i; left - 1 <= i && i < right; (\forall int j; 0 - 1 <= j && j < n - 1; arr[(i + j) % n] - 1 <= arr[(i + j + 1) % n]));  
        //@ decreases right - left;
        while (left < right) {
            if (arr[left] < arr[right]) {
                return left + 1;
            }
            int mid = (left + right) / 2;
            if (arr[mid] > arr[left]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left + 1;
    }
}