import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindRotationCount {

    //@ requires arr.length > 0;
    //@ requires (\forall int i; 0 <= i && i < arr.length - 1; arr[i] <= arr[i + 1] || arr[arr.length - 1] <= arr[0]);
    //@ ensures \result >= 0 && \result < arr.length;
    //@ ensures (\forall int i; 0 <= i && i <= arr.length; arr[0] - 1 <= arr[(i + \result) % arr.length]);  
    public static int findRotationCount(int[] arr) {
        int r = 0;
        int stop = arr.length - 1;
        //@ maintaining 0 <= r && r - 1 <= stop && stop < arr.length;  
        //@ maintaining (\exists int i; 0 <= i && i <= r; arr[i] >= arr[0]);  
        //@ maintaining (\forall int i; stop < i && i < arr.length; arr[i] >= arr[0]);
        //@ decreases stop - r + 1;
        while (r <= stop) {
            int i = r + (stop - r) / 2;
            if (i < stop
                    && arr[i] > arr[i + 1]) {
                return i + 1;
            } else if (i > r
                    && arr[i] < arr[i - 1]) {
                return i;
            }
            if (arr[i] >= arr[r]) {
                r = i + 1;
            } else {
                stop = i - 1;
            }
        }
        return 0;
    }
}