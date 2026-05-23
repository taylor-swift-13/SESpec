import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class SqrtRoot {

    //@ requires num >= 0;
 
 
    public static int sqrtRoot(int num) {
        if (num < 0) {
            return -1;
        }
        int left = 0;
        int right = num;
        //@ maintaining 0 <= left && left - 1 <= right && right <= num;  
 
        //@ decreases right - left;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (mid * mid == num) {
                return mid;
            } else if (mid * mid < num) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return right;
    }
}