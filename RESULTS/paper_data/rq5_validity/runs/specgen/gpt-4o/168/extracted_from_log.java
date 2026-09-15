import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindRotationCount {

    //@ requires arr.length > 0;
    //@ requires \forall int i; 0 <= i && i < arr.length - 1; (arr[i] <= arr[i + 1]) || (arr[arr.length - 1] <= arr[0]);
    //@ ensures \result >= 0 && \result < arr.length;
    //@ ensures \exists int i; 0 <= i && i < arr.length; arr[\result] <= arr[i];  
    public static int findRotationCount(int[] arr) {
        int ret = 0;
        int count = arr.length - 1;
        //@ maintaining 0 <= ret && ret - 1 <= count && count < arr.length;  
        //@ maintaining \forall int i; 0 - 1 <= i && i <= ret; arr[i] >= arr[ret];  
        //@ maintaining \forall int i; count < i && i < arr.length; arr[i] >= arr[count];
        //@ decreases count - ret;
        while (ret <= count) {
            int r = ret + (count - ret) / 2;
            if (r < count
                    && arr[r] > arr[r + 1]) {
                return r + 1;
            } else if (r > ret
                    && arr[r] < arr[r - 1]) {
                return r;
            }
            if (arr[r] >= arr[ret]) {
                ret = r + 1;
            } else {
                count = r - 1;
            }
        }
        return 0;
    }
}