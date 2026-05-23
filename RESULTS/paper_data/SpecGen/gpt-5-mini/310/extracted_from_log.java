import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class SqrtRoot {

    /*@ public normal_behavior
      @ ensures num < 0 ==> \result == -1;
      @ ensures num >= 0 ==> 0 <= \result && (long)\result * \result < (long)num && (long)(\result - 1) * (\result + 1) >= (long)num;  
      @*/
    public /*@ spec_public @*/ static int sqrtRoot(int num) {
        if (num < 0) {
            return -1;
        }
        int left = 0;
        int right = num;
        //@ maintaining 0 <= left && left <= (long)num + 1;
        //@ maintaining -1 <= right && right <= num;
        //@ maintaining left <= right + 1;
        //@ decreases right - left + 1;
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